#include "transaction.h"
#include "ui_transaction.h"

transaction::transaction(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transaction)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);

}

transaction::~transaction()
{
    delete ui;
}

void transaction::on_btnExit_clicked()
{
    close();
}

void transaction::transactionSlot(QString account, QByteArray token)
{
    QString site_url="http://localhost:3000/transaction/" + account;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"), (token));

    transactionManager = new QNetworkAccessManager(this);
    connect(transactionManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(showTransactionSlot(QNetworkReply*)));

    reply = transactionManager->get(request);
}

void transaction::showTransactionSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    tArray = QJsonDocument::fromJson(response_data).array();

    QStandardItemModel *table_model = new QStandardItemModel(tList.size(),4);
    table_model->setHeaderData(0,Qt::Horizontal,QObject::tr("Korttinumero"));
    table_model->setHeaderData(1,Qt::Horizontal,QObject::tr("Tapahtuma"));
    table_model->setHeaderData(2,Qt::Horizontal,QObject::tr("Määrä"));
    table_model->setHeaderData(3,Qt::Horizontal,QObject::tr("Aika"));

    for (int row=0;row < tArray.size(); ++row) {
        QJsonObject jsObj=tArray.at(row).toObject();
        cnum = jsObj["cardnumber"].toString();
        timestamp = jsObj["time"].toString();
        amount = jsObj["transactionamount"].toString();
        ttype = jsObj["transactiontype"].toString();

        QStandardItem *cardnumitem = new QStandardItem(cnum);
        table_model->setItem(row, 0, cardnumitem);
        QStandardItem *timestampitem = new QStandardItem(timestamp);
        table_model->setItem(row, 3, timestampitem);
        QStandardItem *amountitem = new QStandardItem(amount);
        table_model->setItem(row, 2, amountitem);
        QStandardItem *typeitem = new QStandardItem(ttype);
        table_model->setItem(row, 1, typeitem);
    }
    ui->table_model->setModel(table_model);
}





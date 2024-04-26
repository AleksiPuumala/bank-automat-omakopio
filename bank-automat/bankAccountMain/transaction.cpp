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

    table_model = new QStandardItemModel(tList.size(),5);
    table_model->setHeaderData(0,Qt::Horizontal,QObject::tr("Korttinumero"));
    table_model->setHeaderData(1,Qt::Horizontal,QObject::tr("Tapahtuma"));
    table_model->setHeaderData(2,Qt::Horizontal,QObject::tr("Määrä"));
    table_model->setHeaderData(3,Qt::Horizontal,QObject::tr("Aika"));
    table_model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tapahtuma ID"));


    for (int row=0;row < tArray.size(); ++row) {

        QJsonObject jsObj=tArray.at(row).toObject();
        cnum = jsObj["cardnumber"].toString();
        timestamp = jsObj["time"].toString();
        amount = jsObj["transactionamount"].toString();
        ttype = jsObj["transactiontype"].toString();
        tid = QString::number(jsObj["idtransaction"].toInt());

        cardnumitem = new QStandardItem(cnum);
        table_model->setItem(row, 0, cardnumitem);
        timestampitem = new QStandardItem(timestamp);
        table_model->setItem(row, 3, timestampitem);
        amountitem = new QStandardItem(amount);
        table_model->setItem(row, 2, amountitem);
        typeitem = new QStandardItem(ttype);
        table_model->setItem(row, 1, typeitem);
        tranid = new QStandardItem(tid);
        table_model->setItem(row,4,tranid);

    }
    ui->tableview->setModel(table_model);
    for(int row=0;row<tArray.size();row++){
    ui->tableview->hideRow(row);
    }
    rowStart=0;
    rowEnd=5;
    for(int row=rowStart;row<rowEnd;row++){
        ui->tableview->showRow(row);
    }
}

void transaction::on_btnNext_clicked()
{
    nextTable();
}

void transaction::on_btnBack_clicked()
{
    backTable();
}

void transaction::nextTable()
{
    for(int row=0;row<tArray.size();row++){
        ui->tableview->hideRow(row);
    }
    int x=rowStart;
    rowStart=x+5;
    x=rowEnd;
    rowEnd=x+5;
    for(int row=rowStart;row<rowEnd;row++){
        ui->tableview->showRow(row);
    }
}

void transaction::backTable()
{

    for(int row=0;row<tArray.size();row++){
        ui->tableview->hideRow(row);
    }
    rowStart=rowStart-5;
    rowEnd=rowEnd-5;
    for(int row=rowStart;row<rowEnd;row++){
        ui->tableview->showRow(row);
    }
}



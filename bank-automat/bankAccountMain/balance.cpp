#include "balance.h"
#include "ui_balance.h"

balance::balance(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::balance)
{
    ui->setupUi(this);
}

balance::~balance()
{
    delete ui;
}

void balance::on_btnExitBalance_clicked()
{
    close();
}

void balance::balanceDataSlot(QString account, QByteArray intoken)
{
    accountID = account;
    token = intoken;

    QString site_url="http://localhost:3000/account/" + accountID;
    QNetworkRequest request((site_url));
    request.setRawHeader(QByteArray("Authorization"), (token));

    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(balanceSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void balance::balanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
    //QJsonArray accountsArray = json_doc.array();

        QJsonObject json_obj = json_doc.object();
    QString saldoInfo;
    saldoInfo +="Saldo: "+ json_obj["balance"].toString();
    saldoInfo +="Luottoraja: "+ json_obj["creditlimit"].toString();
    saldoInfo +="Tilinumero: "+accountID;

    ui->textEdit->setText(saldoInfo);
       // book+=QString::number(json_obj["id_book"].toInt())+", "+json_obj["name"].toString()+", "+json_obj["author"].toString()+"\r";
    }

    //double balancenum =
    //qDebug()<<balancenum;





    /*
    QString saldoInfo;
    foreach (const QJsonValue &value, accountsArray){

        QJsonObject account = value.toObject();
        int accountID = account["idaccount"].toInt();
        QString balance = account["balance"].toString();
        QString creditlimit = account["creditlimit"].toString();

        saldoInfo += "Tilin ID: " + QString::number(accountID) +
                     "\rSaldo: " + balance +
                     "\rLuottoraja: " + creditlimit + "\r\n";  }*/






#include "withdraw.h"
#include "ui_withdraw.h"
#include <QMessageBox>

withdraw::withdraw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::withdraw)
{
    ui->setupUi(this);
    ui->lineforsum->hide();
    ui->btnEnter->hide();
    ui->label->setText("Valitse nostettava summa");
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_btn20_clicked()
{
    amount.setNum(20);
    QJsonObject name;

    name.insert("idaccount",idaccount);
    name.insert("transactionamount",amount);
    name.insert("cardnumber",cardnumber);


    QString site_url="http://localhost:3000/withdraw";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(token));
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = withdrawManager->put(request, QJsonDocument(name).toJson());

}


void withdraw::on_btn40_clicked()
{
    amount.setNum(40);
    QJsonObject name;
    name.insert("idaccount",idaccount);
    name.insert("transactionamount",amount);
    name.insert("cardnumber",cardnumber);

    QString site_url="http://localhost:3000/withdraw";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(token));
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = withdrawManager->put(request, QJsonDocument(name).toJson());
}


void withdraw::on_btn60_clicked()
{
    amount.setNum(60);
    QJsonObject name;
    name.insert("idaccount",idaccount);
    name.insert("transactionamount",amount);
    name.insert("cardnumber",cardnumber);

    QString site_url="http://localhost:3000/withdraw";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(token));
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = withdrawManager->put(request, QJsonDocument(name).toJson());
}


void withdraw::on_btn100_clicked()
{
    amount.setNum(100);
    QJsonObject name;
    name.insert("idaccount",idaccount);
    name.insert("transactionamount",amount);
    name.insert("cardnumber",cardnumber);

    QString site_url="http://localhost:3000/withdraw";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(token));
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = withdrawManager->put(request, QJsonDocument(name).toJson());
}


void withdraw::on_btn200_clicked()
{
    amount.setNum(200);
    QJsonObject name;
    name.insert("idaccount",idaccount);
    name.insert("transactionamount",amount);
    name.insert("cardnumber",cardnumber);

    QString site_url="http://localhost:3000/withdraw";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(token));
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = withdrawManager->put(request, QJsonDocument(name).toJson());
}


void withdraw::on_btn500_clicked()
{
    amount.setNum(500);
    QJsonObject name;
    name.insert("idaccount",idaccount);
    name.insert("transactionamount",amount);
    name.insert("cardnumber",cardnumber);

    QString site_url="http://localhost:3000/withdraw";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(token));
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = withdrawManager->put(request, QJsonDocument(name).toJson());
}


void withdraw::on_btnOther_clicked()
{
    ui->label->setText("Syötä haluttu summa ja paina Enter");
    ui->lineforsum->show();
    ui->btnEnter->show();
}


void withdraw::on_btnEnter_clicked()
{
    int amount = ui->lineforsum->text().toInt();
    QJsonObject name;
    name.insert("idaccount",idaccount);
    name.insert("transactionamount",amount);
    name.insert("cardnumber",cardnumber);

    QString site_url="http://localhost:3000/withdraw";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setRawHeader(QByteArray("Authorization"),(token));
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = withdrawManager->put(request, QJsonDocument(name).toJson());
}

void withdraw::withdrawDataSlot(QString account, QString cardnum, QByteArray inctoken)
{
    idaccount = account;
    cardnumber = cardnum;
    token = inctoken;
}


void withdraw::on_btnExitWithdraw_clicked()
{
    close();
}

void withdraw::withdrawSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);

    QString strJson(json_doc.toJson(QJsonDocument::Compact));

    QMessageBox box;
    if(strJson=="[{\"Luottoraja ylitetty\":\"Luottoraja ylitetty\"}]"){
        box.setText("Luottoraja ylitetty");
        box.exec();
    }else if(strJson=="[{\"Tilillä ei katetta\":\"Tilillä ei katetta\"}]"){
        box.setText("Tilillä ei katetta");
        box.exec();
    }else if(strJson=="[{\"Nosto suoritettu\":\"Nosto suoritettu\"}]"){
        ptr_takemoney = new takemoney(this);
        connect(ptr_takemoney, SIGNAL(logoutSignal()), this, SLOT(logoutSlot()));
        ptr_takemoney->show();


    }

    reply->deleteLater();

}

void withdraw::logoutSlot()
{
    emit accountlogoutSignal();
    ptr_takemoney->close();
}



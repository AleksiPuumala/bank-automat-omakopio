#include "balance.h"
#include "ui_balance.h"

balance::balance(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::balance)
{
    ui->setupUi(this);
    QString site_url="http://localhost:3000/account";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(balanceSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

balance::~balance()
{
    delete ui;
}

void balance::balanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
    QJsonObject jsonObject = jsonResponse.object();

    QString saldoInfo;
    saldoInfo += "Tilin ID: " +jsonObject["idaccount"].toString() + "\n";
    saldoInfo += "Saldo: " + QString::number(jsonObject["balance"].toInt()) + "\n";
    saldoInfo += "Luottoraja: " + QString::number(jsonObject["creditlimit"].toInt()) + "\n";

    ui->lineEdit->setText(saldoInfo);

    reply->deleteLater();
}

void balance::on_btnExitBalance_clicked()
{
    close();
}




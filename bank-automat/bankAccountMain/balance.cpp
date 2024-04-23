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

    QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

        ui->labelAccount->setText(accountID);
        ui->labelBalance->setText(json_obj["balance"].toString());
        ui->labelCredit->setText(json_obj["creditlimit"].toString());
    }

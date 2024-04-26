#include "account.h"
#include "ui_account.h"
#include "transaction.h"
#include "balance.h"
#include "withdraw.h"

account::account(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::account)


{
    setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);

    ui->btnNosto->hide();
    ui->btnSaldo->hide();
    ui->btnTapahtumat->hide();
    ui->btnTilivalinta1->hide();
    ui->btnTilivalinta2->hide();
    ui->labelTilivalinta->hide();
    ui->btnTilivalinta1->hide();
    ui->btnTilivalinta2->hide();

}

account::~account()
{
    delete ui;
}

void account::on_btnNosto_clicked()
{
    withdraw *ptr_withdraw=new withdraw(this);
    connect(this, SIGNAL(withdrawSignal(QString,QString,QByteArray)),
            ptr_withdraw, SLOT(withdrawDataSlot(QString,QString,QByteArray)));
    emit withdrawSignal(idaccount,cardnumber,token);

    connect(ptr_withdraw, SIGNAL(accountlogoutSignal()),
                                 this, SLOT(logoutSlot()));
    ptr_withdraw->open();
}


void account::on_btnSaldo_clicked()
{
    balance *ptr_balance=new balance(this);
    connect(this, SIGNAL(balanceSignal(QString,QByteArray)),
            ptr_balance, SLOT(balanceDataSlot(QString,QByteArray)));
    emit balanceSignal(idaccount,token);
    ptr_balance->open();
}


void account::on_btnUlos_clicked()
{
    emit logoutSignal();
    account::close();
}


void account::on_btnTapahtumat_clicked()
{
    transaction *ptr_transaction=new transaction(this);

    connect(this, SIGNAL(transactionInSignal(QString,QByteArray)),
            ptr_transaction, SLOT(transactionSlot(QString,QByteArray)));
    emit transactionInSignal(idaccount,token);

    ptr_transaction->open();
}


void account::accountSlot(QNetworkReply* reply)
{
    response_data=reply->readAll();
    json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    if(json_array.size()>1){

        QVariant jsonVariant = json_doc.toVariant();
        QVariantList jsonArray = jsonVariant.toList();

        QVariantMap item1 = jsonArray.at(0).toMap();
        QVariantMap item2 = jsonArray.at(1).toMap();

        int id1 = item1.value("idaccount").toInt();
        acc1 = QString::number(id1);
        int id2 = item2.value("idaccount").toInt();
        acc2 = QString::number(id2);

        ui->btnTilivalinta1->setText("Tili "+acc1);
        ui->btnTilivalinta2->setText("Tili "+acc2);
        ui->labelTilivalinta->show();
        ui->btnTilivalinta1->show();
        ui->btnTilivalinta2->show();

    } else {

        QVariant jsonVariant = json_doc.toVariant();
        QVariantList jsonArray = jsonVariant.toList();

        QVariantMap item = jsonArray.at(0).toMap();

        idaccount=QString::number(item.value("idaccount").toInt());
        ui->btnNosto->show();
        ui->btnSaldo->show();
        ui->btnTapahtumat->show();
        ui->btnTapahtumat->show();
    }
}

void account::cardnumSlot(QString incNumber, QByteArray inctoken)
{
    cardnumber = incNumber;
    token = inctoken;
}

void account::on_btnTilivalinta1_clicked()
{

    idaccount = acc1;

    ui->btnNosto->show();
    ui->btnSaldo->show();
    ui->btnTapahtumat->show();
    ui->btnTapahtumat->show();
    ui->labelTilivalinta->hide();
    ui->btnTilivalinta1->hide();
    ui->btnTilivalinta2->hide();
}

void account::on_btnTilivalinta2_clicked()
{

    idaccount = acc2;

    ui->btnNosto->show();
    ui->btnSaldo->show();
    ui->btnTapahtumat->show();
    ui->btnTapahtumat->show();
    ui->labelTilivalinta->hide();
    ui->btnTilivalinta1->hide();
    ui->btnTilivalinta2->hide();
}

void account::logoutSlot()
{
    emit logoutSignal();
    account::close();
}




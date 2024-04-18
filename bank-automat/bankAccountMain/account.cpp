#include "account.h"
#include "ui_account.h"
#include "transaction.h"
#include "balance.h"
#include "withdraw.h"

account::account(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::account)
{
    ui->setupUi(this);
    qDebug()<<"account luotu";

    ui->btnNosto->hide();
    ui->btnSaldo->hide();
    ui->btnTapahtumat->hide();
    ui->btnTapahtumat_2->hide();
    ui->btnTilivalinta1->hide();
    ui->btnTilivalinta2->hide();
    ui->labelTilivalinta->hide();
}

account::~account()
{
    delete ui;
}

void account::on_btnNosto_clicked()
{
    withdraw *ptr_withdraw=new withdraw(this);
    ptr_withdraw->open();
}


void account::on_btnSaldo_clicked()
{
    balance *ptr_balance=new balance(this);
    ptr_balance->open();
}


void account::on_btnUlos_clicked()
{

}


void account::on_btnTapahtumat_clicked()
{
    transaction *ptr_transaction=new transaction(this);
    ptr_transaction->open();
}

void account::accountSlot(QNetworkReply* reply)
{
    qDebug()<<"account slot ok ";
    response_data=reply->readAll();
    qDebug()<<response_data;
    json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    if(json_array.size()>1){
        qDebug()<<"monta tiliä";

        QVariant jsonVariant = json_doc.toVariant();
        QVariantList jsonArray = jsonVariant.toList();

        QVariantMap item1 = jsonArray.at(0).toMap();
        QVariantMap item2 = jsonArray.at(1).toMap();

        int id1 = item1.value("idaccount").toInt();
        QString acc1 = QString::number(id1);
        int id2 = item2.value("idaccount").toInt();
        QString acc2 = QString::number(id2);


        qDebug()<< acc1;
        ui->btnTilivalinta1->setText("Tili "+acc1);
        ui->btnTilivalinta2->setText("Tili "+acc2);
        ui->labelTilivalinta->show();
        ui->btnTilivalinta1->show();
        ui->btnTilivalinta2->show();

    } else {
        ui->btnNosto->show();
        ui->btnSaldo->show();
        ui->btnTapahtumat->show();
        ui->btnTapahtumat->show();
    }
}

void account::cardnumSlot(QString incNumber)
{
    cardnumber = incNumber;
}

void account::on_btnTilivalinta1_clicked()
{
    QVariant jsonVariant = json_doc.toVariant();
    QVariantList jsonArray = jsonVariant.toList();

    QVariantMap item = jsonArray.at(0).toMap();

    int id1 = item.value("idaccount").toInt();
    idaccount = QString::number(id1);

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
    QVariant jsonVariant = json_doc.toVariant();
    QVariantList jsonArray = jsonVariant.toList();

    QVariantMap item = jsonArray.at(0).toMap();

    int id1 = item.value("idaccount").toInt();
    idaccount = QString::number(id1);

    ui->btnNosto->show();
    ui->btnSaldo->show();
    ui->btnTapahtumat->show();
    ui->btnTapahtumat->show();
    ui->labelTilivalinta->hide();
    ui->btnTilivalinta1->hide();
    ui->btnTilivalinta2->hide();
}




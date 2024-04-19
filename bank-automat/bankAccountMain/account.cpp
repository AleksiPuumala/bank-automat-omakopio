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

void account::logoutSlot()
{
    account::close();
}


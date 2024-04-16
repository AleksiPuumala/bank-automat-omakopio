#include "withdraw.h"
#include "ui_withdraw.h"

withdraw::withdraw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::withdraw)
{
    ui->setupUi(this);
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_btn20_clicked()
{

}


void withdraw::on_btn40_clicked()
{

}


void withdraw::on_btn60_clicked()
{

}


void withdraw::on_btn100_clicked()
{

}


void withdraw::on_btn200_clicked()
{

}


void withdraw::on_btn500_clicked()
{

}


void withdraw::on_btnOther_clicked()
{

}


void withdraw::on_btnExitWithdraw_clicked()
{
    close();
}


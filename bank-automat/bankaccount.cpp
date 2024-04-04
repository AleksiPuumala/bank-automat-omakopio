#include "bankaccount.h"
#include "ui_bankaccount.h"

bankaccount::bankaccount(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bankaccount)
{
    ui->setupUi(this);
}

bankaccount::~bankaccount()
{
    delete ui;
}

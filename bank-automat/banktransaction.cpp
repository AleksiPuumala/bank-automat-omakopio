#include "banktransaction.h"
#include "ui_banktransaction.h"

banktransaction::banktransaction(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::banktransaction)
{
    ui->setupUi(this);
}

banktransaction::~banktransaction()
{
    delete ui;
}

#include "banktransfer.h"
#include "ui_banktransfer.h"

banktransfer::banktransfer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::banktransfer)
{
    ui->setupUi(this);
}

banktransfer::~banktransfer()
{
    delete ui;
}

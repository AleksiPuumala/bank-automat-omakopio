#include "loginscreen.h"
#include "ui_loginscreen.h"

loginscreen::loginscreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginscreen)
{
    ui->setupUi(this);
}

loginscreen::~loginscreen()
{
    delete ui;
}

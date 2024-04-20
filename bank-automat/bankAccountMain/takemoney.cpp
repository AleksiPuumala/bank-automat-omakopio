#include "takemoney.h"
#include "ui_takemoney.h"
#include <QTimer>

takemoney::takemoney(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::takemoney)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(logoutSlot()));
    timer->start(5000);
}

takemoney::~takemoney()
{
    delete ui;
}

void takemoney::logoutSlot()
{
    emit logoutSignal();
}

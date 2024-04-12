#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptr_pinui = new bankPinUi(this);
    connect(ptr_pinui, SIGNAL(loginSignal(QByteArray)),
            this, SLOT (loginSlot(QByteArray)));
    ptr_pinui->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginSlot(QByteArray response_data)
{
    qDebug()<<"mainwindow slot ok";
}

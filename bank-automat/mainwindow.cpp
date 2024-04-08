#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptr_pinui = new bankPinUi(this);
    ptr_pinui->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

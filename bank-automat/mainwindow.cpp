#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptr_account = new account(this);
    ptr_account->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

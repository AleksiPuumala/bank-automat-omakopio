#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->creditSyotetty, &QPushButton::clicked, this, &MainWindow::creditSyotettyClicked);
    connect(ui->debitSyotetty, &QPushButton::clicked, this, &MainWindow::debitSyotettyClicked);
    connect(ui->kaksoisSyotetty, &QPushButton::clicked, this, &MainWindow::kaksoisSyotettyClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::creditSyotettyClicked()
{
    ui->infoTeksti->setText("Credit-kortti syötetty");
}

void MainWindow::debitSyotettyClicked()
{
    ui->infoTeksti->setText("Debit-kortti syötetty");
}

void MainWindow::kaksoisSyotettyClicked()
{
    ui->infoTeksti->setText("Kaksoiskortti syötetty");
}

// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serialPort(new QSerialPort(this))
{
    ui->setupUi(this);

    serialPort->setPortName("COM4"); // TÄHÄN USB-PORTIN KANAVA
    serialPort->setBaudRate(QSerialPort::Baud9600); // Siirtonopeus

    // Kun sarjaporttiin tulee uutta dataa, kutsu readSerialData
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // avaa sarjaportti
    if (serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "Serial port avattu";
    } else {
        qDebug() << "Serial port ei avaudu";
    }
}

MainWindow::~MainWindow()
{
    // Serialportti kiinni kun mainwindowin sulkee
    serialPort->close();
    delete ui;
}

void MainWindow::readSerialData()
{
    // Tallenna sarjaportin data QStringiin
    serialData = QString(serialPort->readAll());

    // Etsi datasta määriteltyjä kortteja
    if (serialData.contains("060006235F"))
    {
        ui->infoTeksti->setText("Debit-kortti syötettiin");
    }
    else if (serialData.contains("06000620D0"))
    {
        ui->infoTeksti->setText("Credit-kortti syötettiin");
    }
    else if (serialData.contains("0500CB33C7"))
    {
        ui->infoTeksti->setText("Kaksoiskortti syötettiin");
    }
    else
    {
        // Jos käytetään tuntematonta korttia
        ui->infoTeksti->setText("Virheellinen kortti");
    }
}

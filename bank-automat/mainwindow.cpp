#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serialPort(new QSerialPort(this))

{
    ui->setupUi(this);

    serialPort->setPortName("COM5"); // TÄHÄN USB-PORTIN KANAVA
    serialPort->setBaudRate(QSerialPort::Baud9600); // Siirtonopeus

    // Kun sarjaporttiin tulee uutta dataa, kutsu readSerialData
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // avaa sarjaportti
    if (serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "Serial port avattu";
    } else {
        qDebug() << "Serial port ei avaudu";
    }
    serialData = "";
}



MainWindow::~MainWindow()
{
    // Serialportti kiinni kun mainwindowin sulkee
    serialPort->close();
    delete ui;
}

void MainWindow::readSerialData()
{
    // Tallenna sarjaportin data QStringiin serialData
    // Jos serialData sisältää korttinumeron -> ei avata uusia pin olioita
    if(serialData.size()<=0){
        serialData = QString(serialPort->readAll());
        ptr_pinui = new bankPinUi(this);
        connect(ptr_pinui, SIGNAL(loginSignal(QByteArray)),
                this, SLOT (loginSlot(QByteArray)));
        connect(this, SIGNAL (pinSignal(QString)),
                ptr_pinui, SLOT(cardNum(QString)));

        emit pinSignal(serialData);
        ptr_pinui->show();
    }

}

void MainWindow::loginSlot(QByteArray response_data) // Lähetä kortin numero ja webtoken
{
    ptr_pinui->close();
    qDebug()<<"mainwindow slot ok";

    ptr_account = new account(this);
    cardnumber = serialData.remove(0, 3), serialData.remove(10, 3);
    qDebug()<<serialData;


    QString site_url="http://localhost:3000/cardselect/"+serialData;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray token= "Bearer " + response_data;
    request.setRawHeader(QByteArray("Authorization"),(token));

    cardManager = new QNetworkAccessManager(this);
    connect(cardManager, SIGNAL(finished (QNetworkReply*)), ptr_account, SLOT(accountSlot(QNetworkReply*)));

    reply = cardManager->get(request);

    ptr_account->show();
}





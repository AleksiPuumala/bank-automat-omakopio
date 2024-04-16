#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serialPort(new QSerialPort(this)),
    ptr_pinui(new bankPinUi(this))

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
    ptr_pinui = new bankPinUi(this);
    connect(ptr_pinui, SIGNAL(loginSignal(QByteArray)),
            this, SLOT (loginSlot(QByteArray)));
    connect(this, SIGNAL (pinSignal(QString)),
            ptr_pinui, SLOT(cardNum(QString)));

    emit pinSignal(serialData);
    ptr_pinui->show();

}

void MainWindow::loginSlot(QByteArray response_data) // Lähetä kortin numero ja webtoken
{
    qDebug()<<"mainwindow slot ok";
    qDebug()<< response_data;


        // Testaa toimiiko

    QString site_url="http://localhost:3000/cardselect";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QString token= "Bearer " + response_data;
    request.setRawHeader("Authorization", token.toLocal8Bit());

    cardManager = new QNetworkAccessManager(this);
    connect(cardManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(accountSlot()));

    reply = cardManager->get(request);
    qDebug()<< reply->readAll();
}


void MainWindow::accountSlot()
{
    qDebug()<<"account slot ok";
}


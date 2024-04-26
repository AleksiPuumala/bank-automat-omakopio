#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"

#include <QPixmap>

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
    ui->infoTeksti->setReadOnly(true);

    // Kuva
    picManager = new QNetworkAccessManager(this);
    connect(picManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(pictureSlot(QNetworkReply*)));
    QUrl url("http://localhost:3000/image/aku.jpeg");
    QNetworkRequest request(url);
    picManager->get(request);
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

        //pinui logout signaali
        connect(ptr_pinui, SIGNAL(logoutPinSignal()), this, SLOT(logoutSlot()));

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
    //logout signal accountille
    connect(ptr_account, SIGNAL(logoutSignal()),
            this, SLOT(logoutSlot()));

    // Lähetetään korttinumero accountille
    connect(this , SIGNAL(cardnumSignal(QString,QByteArray)),
            ptr_account, SLOT(cardnumSlot(QString,QByteArray)));


    QString site_url="http://localhost:3000/cardselect/"+serialData;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray token= "Bearer " + response_data;
    request.setRawHeader(QByteArray("Authorization"),(token));
    emit cardnumSignal(cardnumber, token);
    cardManager = new QNetworkAccessManager(this);
    connect(cardManager, SIGNAL(finished (QNetworkReply*)), ptr_account, SLOT(accountSlot(QNetworkReply*)));

    reply = cardManager->get(request);

    ptr_account->show();
}

void MainWindow::logoutSlot()
{
    cardnumber = nullptr;
    serialData = nullptr;
}

void MainWindow::on_ohita_clicked()
{
    ptr_account = new account(this);
    ptr_account->show();
}

void MainWindow::pictureSlot(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug()<<"Error in"<<reply->url()<<":"<<reply->errorString();
        return;
    }else{
        QByteArray jpegData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);
        ui->labelPic->setPixmap(pixmap);
    }
}



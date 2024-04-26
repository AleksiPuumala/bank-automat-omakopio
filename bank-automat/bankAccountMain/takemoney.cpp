#include "takemoney.h"
#include "ui_takemoney.h"
#include <QTimer>

#include <QPixmap>

takemoney::takemoney(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::takemoney)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(logoutSlot()));
    timer->start(5000);

    //Kuva
    imageManager = new QNetworkAccessManager(this);
    connect(imageManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(imageSlot(QNetworkReply*)));
    QUrl url("http://localhost:3000/image/roope.jpeg");
    QNetworkRequest request(url);
    imageManager->get(request);
}

takemoney::~takemoney()
{
    delete ui;
}

void takemoney::logoutSlot()
{
    emit logoutSignal();
}

void takemoney::imageSlot(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug()<<"Error in"<<reply->url()<<":"<<reply->errorString();
        return;
    }else{
        QByteArray jpegData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);
        int w = ui->label_image->width();
        int h = ui->label_image->height();
        ui->label_image->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));
    }
}

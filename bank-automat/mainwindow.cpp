#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serialPort(new QSerialPort(this)),
    ptr_pinui(new bankPinUi(this))
{
    ui->setupUi(this);

    ui->debit->hide(); //näitä tarvitaan jos käytetään kaksoiskorttia
    ui->credit->hide();

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

    // Liitetään debit- ja credit-painikkeiden käsittelijät
    connect(ui->debit, &QPushButton::clicked, this, &MainWindow::selectDebitCard);
    connect(ui->credit, &QPushButton::clicked, this, &MainWindow::selectCreditCard);
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
    // Etsi datasta määriteltyjä kortteja ja avaa pinkoodi-ikkuna jos kortti löytyy
    /* if (serialData.contains("060006235F"))
    {
       ui->infoTeksti->setText("Debit-kortti syötettiin");
         ptr_pinui->show();
    }
    else if (serialData.contains("06000620D0"))
    {
        ui->infoTeksti->setText("Credit-kortti syötettiin");
        ptr_pinui->show();
    }
    else if (serialData.contains("0500CB33C7"))
    {
        ui->infoTeksti->setText("Valitse kortin tyyppi");
        ui->debit->show();
        ui->credit->show();
    }
    else
    {
        // Jos käytetään tuntematonta korttia
        ui->infoTeksti->setText("Virheellinen kortti");
    } */
}

void MainWindow::selectCreditCard()
{
    ui->infoTeksti->setText("Credit-kortti valittu");
    ptr_pinui->show();
}

void MainWindow::selectDebitCard()
{
    ui->infoTeksti->setText("Debit-kortti valittu");
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
    connect(cardManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(accountSlot(QNetworkReply*)));

    reply = cardManager->get(request);
    qDebug()<< reply->readAll();
}

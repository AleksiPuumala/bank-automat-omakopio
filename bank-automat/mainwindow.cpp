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
    ptr_pinui = new bankPinUi(this);
    connect(ptr_pinui, SIGNAL(loginSignal(QByteArray)),
            this, SLOT (loginSlot(QByteArray)));
    ptr_pinui->show();
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

    // Etsi datasta määriteltyjä kortteja ja avaa pinkoodi-ikkuna jos kortti löytyy
    if (serialData.contains("060006235F"))
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
    }
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
void MainWindow::loginSlot(QByteArray response_data)
{
    qDebug()<<"mainwindow slot ok";
}

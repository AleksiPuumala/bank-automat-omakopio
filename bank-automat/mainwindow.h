#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "bankpinui.h"
#include "account.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSerialData();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QString serialData; // Tähän tallennetaan serialportin data

    bankPinUi * ptr_pinui;
    account * ptr_account;

    QString cardnumber;

    QNetworkAccessManager *cardManager;
    QNetworkReply *reply;

private slots:
    void loginSlot(QByteArray);

signals:
    void pinSignal(QString);

};

#endif // MAINWINDOW_H

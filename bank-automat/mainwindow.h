#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "bankpinui.h"
#include "account.h"
#include <QLabel>

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
    void loginSlot(QByteArray);
    void logoutSlot();

    void pictureSlot(QNetworkReply *reply);


private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QString serialData; // Tähän tallennetaan serialportin data

    bankPinUi * ptr_pinui;
    account * ptr_account;

    QString cardnumber;

    QNetworkAccessManager *cardManager;
    QNetworkReply *reply;

    QNetworkAccessManager *picManager;
    QByteArray response_data;

signals:
    void pinSignal(QString);
    void cardnumSignal(QString cardnumber, QByteArray token);

};

#endif // MAINWINDOW_H

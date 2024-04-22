#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <bankAccountMain_global.h>
#include "transaction.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class account;
}

class BANKACCOUNTMAIN_EXPORT account : public QDialog
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = nullptr);
    ~account();



private slots:
    void on_btnNosto_clicked();
    void on_btnSaldo_clicked();
    void on_btnUlos_clicked();
    void on_btnTapahtumat_clicked();
    void on_btnTilivalinta2_clicked();
    void on_btnTilivalinta1_clicked();

    void accountSlot(QNetworkReply*);
    void cardnumSlot(QString incNumber, QByteArray inctoken);

    void logoutSlot();


private:
    Ui::account *ui;
    transaction *ptr_transaction;
    QNetworkReply *reply;
    QByteArray response_data;

    QString cardnumber;     // vastaanotettu korttinumero
    QString idaccount;      //tilin id
    QByteArray token;       //kirjautumisesta saatu webtoken

    QString acc1;           //yhdistelmäkortin valintaan käytettävät muuttujat
    QString acc2;

    QJsonDocument json_doc;
signals:
    void logoutSignal();
};

#endif // ACCOUNT_H

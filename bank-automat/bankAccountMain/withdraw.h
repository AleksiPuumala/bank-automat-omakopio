#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDialog>
#include "takemoney.h"
#include <QTimer>

namespace Ui {
class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();

private slots:
    void on_btn20_clicked();
    void on_btn40_clicked();
    void on_btn60_clicked();
    void on_btn100_clicked();
    void on_btn200_clicked();
    void on_btn500_clicked();
    void on_btnOther_clicked();
    void on_btnExitWithdraw_clicked();

    void withdrawSlot(QNetworkReply *reply);
    void logoutSlot();

    void on_btnEnter_clicked();

    void withdrawDataSlot(QString account, QString cardnum, QByteArray inctoken);

private:
    Ui::withdraw *ui;

    QString amount;
    QString cardnumber;
    QString idaccount;

    QNetworkAccessManager *withdrawManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QByteArray token;

    takemoney * ptr_takemoney;
};

#endif // WITHDRAW_H

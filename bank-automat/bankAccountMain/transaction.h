#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QList>
#include <QStandardItemModel>

namespace Ui {
class transaction;
}

class transaction : public QDialog
{
    Q_OBJECT

public:
    explicit transaction(QWidget *parent = nullptr);
    ~transaction();

private slots:
    void on_btnExit_clicked();
    void transactionSlot(QString, QByteArray);
    void showTransactionSlot(QNetworkReply*);

private:
    Ui::transaction *ui;
    QNetworkReply *reply;
    QByteArray response_data;
    QNetworkAccessManager *transactionManager;
    QString cnum, timestamp, amount, ttype;
    QList<QString> tList {cnum, timestamp, amount, ttype};
signals:
    void transactionLogoutSignal();
};

#endif // TRANSACTION_H

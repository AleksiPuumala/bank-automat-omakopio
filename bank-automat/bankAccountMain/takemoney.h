#ifndef TAKEMONEY_H
#define TAKEMONEY_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>


namespace Ui {
class takemoney;
}

class takemoney : public QDialog
{
    Q_OBJECT

public:
    explicit takemoney(QWidget *parent = nullptr);
    ~takemoney();

private:
    Ui::takemoney *ui;
    QNetworkAccessManager *imageManager;
    QByteArray response_data;

private slots:
    void logoutSlot();

    void imageSlot(QNetworkReply *reply);

signals:
    void logoutSignal();

};

#endif // TAKEMONEY_H

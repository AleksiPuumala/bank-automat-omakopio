#ifndef TAKEMONEY_H
#define TAKEMONEY_H

#include <QDialog>


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

private slots:
    void logoutSlot();

signals:
    void logoutSignal();

};

#endif // TAKEMONEY_H

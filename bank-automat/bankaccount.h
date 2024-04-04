#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QDialog>

namespace Ui {
class bankaccount;
}

class bankaccount : public QDialog
{
    Q_OBJECT

public:
    explicit bankaccount(QWidget *parent = nullptr);
    ~bankaccount();

private:
    Ui::bankaccount *ui;
};

#endif // BANKACCOUNT_H

#ifndef BANKTRANSACTION_H
#define BANKTRANSACTION_H

#include <QDialog>

namespace Ui {
class banktransaction;
}

class banktransaction : public QDialog
{
    Q_OBJECT

public:
    explicit banktransaction(QWidget *parent = nullptr);
    ~banktransaction();

private:
    Ui::banktransaction *ui;
};

#endif // BANKTRANSACTION_H

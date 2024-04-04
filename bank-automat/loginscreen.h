#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>

namespace Ui {
class loginscreen;
}

class loginscreen : public QDialog
{
    Q_OBJECT

public:
    explicit loginscreen(QWidget *parent = nullptr);
    ~loginscreen();

private:
    Ui::loginscreen *ui;
};

#endif // LOGINSCREEN_H

#ifndef MONEYONSCREENFRAME_H
#define MONEYONSCREENFRAME_H

#include <QFrame>

namespace Ui {
class MoneyOnScreenFrame;
}

class MoneyOnScreenFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MoneyOnScreenFrame(QWidget *parent = 0);
    ~MoneyOnScreenFrame();

private:
    Ui::MoneyOnScreenFrame *ui;
};

#endif // MONEYONSCREENFRAME_H

#ifndef MENUAMOUNT_H
#define MENUAMOUNT_H

#include <QFrame>

namespace Ui {
class MenuAmount;
}

class MenuAmount : public QFrame
{
    Q_OBJECT

public:
    explicit MenuAmount(QWidget *parent = 0);
    ~MenuAmount();

private:
    Ui::MenuAmount *ui;
};

#endif // MENUAMOUNT_H

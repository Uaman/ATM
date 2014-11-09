#ifndef MENUSTATES_H
#define MENUSTATES_H

#include <QMainWindow>
#include "FramesAndWidgets/MainWindow.h"

namespace Ui {
class MainWindow;
}
class MenuStates:public QObject
{
    Q_OBJECT
public:
    explicit MenuStates(QWidget *parent = 0);
    MainWindow* _window;
    ~MenuStates();

signals:

public slots:
    //Main window(Logining) slots
    void signalLogInClicked(void);
    void cardNumberEntered(void);
    void passwordEntered(void);

    //Main menu slots
    void signalPayClicked(void);

    //Tacking money slots
    void takeOutSomeSum();

private:
    QString _cardNumber;
    QString _password;
    QFrame* _currentFrame;

};

#endif // MENUSTATES_H

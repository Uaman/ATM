#ifndef MENUSTATES_H
#define MENUSTATES_H
//Developed by Dima Zvazhii
//08.11.14
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
    inline const std::string cardNumber() const {return _cardNumber.toStdString();}
    inline const std::string password() const {return _password.toStdString();}
    void allowLogIn();


    ~MenuStates();

signals:
    void signal_try_password();

public slots:
    //Base window
    void closingWindow();

    //Main window(Logining) slots
    void signalLogInClicked(void);
    void cardNumberEntered(void);
    void passwordEntered(void);

    //Main menu slots
    void signalPayClicked(void);
    void balanceOnScreen(void);
    void onSendingMoney(void);

    //Tacking money slots
    void takeOutSomeSum();
    void anotherSum();
    void backToMainMenu();

    //Sending money slots


    //AnotherSumFrame slots
    void backOnTakingMoneyWindow();


private:
    QString _cardNumber;
    QString _password;
    QFrame* _currentFrame;

};

#endif // MENUSTATES_H

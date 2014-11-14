//Developed by Dima Zvazhii
//08.11.14
#include "qobject.h"
#include "MenuStates.h"
#include "FramesAndWidgets/MainMenu.h"
#include "FramesAndWidgets/MainWindow.h"
#include "FramesAndWidgets/MainWindowFrame.h"
#include "FramesAndWidgets/TakingMoney.h"
#include "FramesAndWidgets/MoneyOnScreenFrame.h"
#include "FramesAndWidgets/SendingMoneyFrame.h"
#include "../logic/ATM.h"
#include "../logic/DataStorage.h"
#include "FramesAndWidgets/AnotherSumFrame.h"
#include <iostream>

MenuStates::MenuStates(QWidget *parent):
    _window(new MainWindow(parent)),
    _currentFrame(nullptr),
    _cardNumber(""),
    _password("")
{
    connect(_window,SIGNAL(closeWindow()),SLOT(closingWindow()));
    MainWindowFrame* winFr=new MainWindowFrame();
    connect(winFr,SIGNAL(signalLogInClicked()),SLOT(signalLogInClicked()));
    connect(winFr,SIGNAL(loginEntered()),SLOT(cardNumberEntered()));
    connect(winFr,SIGNAL(passwordEntered()),SLOT(passwordEntered()));
    _currentFrame=winFr;
    winFr=0;
    _window->addSonFrame(_currentFrame);
}

//closing window
void MenuStates::closingWindow()
{
    _window->close();
}

void MenuStates::signalLogInClicked(void)
{
    emit signal_try_password();
}

//works after checking password
//if okay redirect to main window
void MenuStates::allowLogIn()
{
    delete _currentFrame;
    MainMenu* menu=new MainMenu();
    connect(menu,SIGNAL(signal_on_pay_clicked()),SLOT(signalPayClicked()));
    connect(menu,SIGNAL(singal_balance_on_screen()),SLOT(balanceOnScreen()));
    connect(menu,SIGNAL(signal_sending_money()),SLOT(onSendingMoney()));
    _currentFrame=menu;
    menu=0;
    _window->addSonFrame(_currentFrame);
}

//redirecting to SendingMoneyFrame
void MenuStates::onSendingMoney()
{
    delete _currentFrame;
    SendingMoneyFrame* send=new SendingMoneyFrame();
    connect(send,SIGNAL(backToMainMenu()),SLOT(backToMainMenu()));
    _currentFrame=send;
    send=0;
    _window->addSonFrame(_currentFrame);
}

//redirecting to MoneyOnScreenFrame
void MenuStates::balanceOnScreen()
{
    delete _currentFrame;
    MoneyOnScreenFrame* onScreen= new MoneyOnScreenFrame();
    connect(onScreen,SIGNAL(backToMainMenu()),SLOT(backToMainMenu()));
    connect(onScreen,SIGNAL(goToTakingMoney()),SLOT(backOnTakingMoneyWindow()));
    _currentFrame=onScreen;
    _window->addSonFrame(_currentFrame);
}

void MenuStates::cardNumberEntered()
{
    MainWindowFrame* mFr=static_cast<MainWindowFrame*>(_currentFrame);
    _cardNumber=mFr->getCardNumber();
    mFr=0;
}


//Method for working with taking money function
//Loads taking money window
void MenuStates::signalPayClicked()
{
    delete _currentFrame;
    TakingMoney* monyTaker=new TakingMoney();
    connect(monyTaker,SIGNAL(takeOutMoney()),SLOT(takeOutSomeSum()));
    connect(monyTaker,SIGNAL(anotherSum()),SLOT(anotherSum()));
    connect(monyTaker,SIGNAL(signalBack()),SLOT(backToMainMenu()));
    _currentFrame=monyTaker;
    monyTaker=0;
    _window->addSonFrame(_currentFrame);
}

//The slot for going back to MainMenu window
void MenuStates::backToMainMenu()
{
    delete _currentFrame;
    MainMenu* menu=new MainMenu();
    connect(menu,SIGNAL(signal_on_pay_clicked()),SLOT(signalPayClicked()));
    connect(menu,SIGNAL(singal_balance_on_screen()),SLOT(balanceOnScreen()));
    connect(menu,SIGNAL(signal_sending_money()),SLOT(onSendingMoney()));
    _currentFrame=menu;
    menu=0;
    _window->addSonFrame(_currentFrame);
}


//slot allow redirecting on AnotherSumFrame
void MenuStates::anotherSum()
{
    delete _currentFrame;
    AnotherSumFrame* another=new AnotherSumFrame();
    connect(another,SIGNAL(signalBackOnTackingMoneyFrame()),SLOT(backOnTakingMoneyWindow()));
    _currentFrame=another;
    another=0;
    _window->addSonFrame(_currentFrame);
}


//allows returning to TakingMoney window
void MenuStates::backOnTakingMoneyWindow()
{
    delete _currentFrame;
    TakingMoney* monyTaker=new TakingMoney();
    connect(monyTaker,SIGNAL(takeOutMoney()),SLOT(takeOutSomeSum()));
    connect(monyTaker,SIGNAL(anotherSum()),SLOT(anotherSum()));
    connect(monyTaker,SIGNAL(signalBack()),SLOT(backToMainMenu()));
    _currentFrame=monyTaker;
    monyTaker=0;
    _window->addSonFrame(_currentFrame);
}


void MenuStates::takeOutSomeSum()
{
    //you can receive the sum from
    TakingMoney* monyTaker=static_cast<TakingMoney*>(_currentFrame);
    /*here it is*/monyTaker->getSumToTakeOut();
    monyTaker=0;
}

void MenuStates::passwordEntered()
{
    MainWindowFrame* mFr=static_cast<MainWindowFrame*>(_currentFrame);
    _password=mFr->getPassword();
    mFr=0;
}

MenuStates::~MenuStates()
{
//    if(_currentFrame!=nullptr)
//        delete _currentFrame;
//    if(_window!=nullptr)
//        delete _window;

}

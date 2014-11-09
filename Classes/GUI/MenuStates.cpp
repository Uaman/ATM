#include "qobject.h"
#include "MenuStates.h"
#include "FramesAndWidgets/MainMenu.h"
#include "FramesAndWidgets/MainWindow.h"
#include "FramesAndWidgets/MainWindowFrame.h"
#include "FramesAndWidgets/TakingMoney.h"
#include "../logic/ATM.h"
#include "../logic/DataStorage.h"
#include <iostream>

MenuStates::MenuStates(QWidget *parent):
    _window(new MainWindow(parent)),
    _currentFrame(nullptr)
{
    MainWindowFrame* winFr=new MainWindowFrame();
    connect(winFr,SIGNAL(signalLogInClicked()),SLOT(signalLogInClicked()));
    connect(winFr,SIGNAL(loginEntered()),SLOT(cardNumberEntered()));
    connect(winFr,SIGNAL(passwordEntered()),SLOT(passwordEntered()));
    _currentFrame=winFr;
    winFr=0;
    _window->addSonFrame(_currentFrame);
}

void MenuStates::signalLogInClicked(void)
{

   // checkCard();
    delete _currentFrame;
    MainMenu* menu=new MainMenu();
    connect(menu,SIGNAL(signal_on_pay_clicked()),SLOT(signalPayClicked()));
    _currentFrame=menu;
    menu=0;
    _window->addSonFrame(_currentFrame);
}

void MenuStates::cardNumberEntered()
{
    MainWindowFrame* mFr=static_cast<MainWindowFrame*>(_currentFrame);
    _cardNumber=mFr->getCardNumber();
    mFr=0;
}

void MenuStates::signalPayClicked()
{
    delete _currentFrame;
    TakingMoney* monyTaker=new TakingMoney();
    connect(monyTaker,SIGNAL(takeOutMoney()),SLOT(takeOutSomeSum()));
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

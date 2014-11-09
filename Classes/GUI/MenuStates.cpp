#include "qobject.h"
#include "MenuStates.h"
#include "FramesAndWidgets/MainMenu.h"
#include "FramesAndWidgets/MainWindow.h"
#include "FramesAndWidgets/MainWindowFrame.h"

MenuStates::MenuStates(QWidget *parent):
    _window(new MainWindow(parent)),
    _currentFrame(nullptr)
{
    MainWindowFrame* winFr=new MainWindowFrame();
    connect(winFr,SIGNAL(signalLogInClicked()),SLOT(signalLogInClicked()));
    _currentFrame=winFr;
    winFr=0;
    _window->addSonFrame(_currentFrame);
}





void MenuStates::signalLogInClicked(void)
{
    delete _currentFrame;
    MainMenu* menu=new MainMenu();
    connect(menu,SIGNAL(signal_on_pay_clicked()),SLOT(signalPayClicked()));
    _currentFrame=menu;
    menu=0;
    _window->addSonFrame(_currentFrame);
}

void MenuStates::signalPayClicked()
{
    delete _currentFrame;
    _currentFrame=new MainWindowFrame();
    _window->addSonFrame(_currentFrame);
}

MenuStates::~MenuStates()
{
//    if(_currentFrame!=nullptr)
//        delete _currentFrame;
//    if(_window!=nullptr)
//        delete _window;

}

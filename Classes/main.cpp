#include "GUI/FramesAndWidgets/MainWindow.h"
#include "GUI/FramesAndWidgets/MainMenu.h"
#include "GUI/MenuStates.h"
#include <QApplication>
#include "logic/ATM.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ATM atm;
    atm.startATM();

    return a.exec();
}

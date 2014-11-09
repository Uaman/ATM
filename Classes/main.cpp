#include "GUI/FramesAndWidgets/MainWindow.h"
#include "GUI/FramesAndWidgets/MainMenu.h"
#include "GUI/MenuStates.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuStates st;
    st._window->show();

    return a.exec();
}

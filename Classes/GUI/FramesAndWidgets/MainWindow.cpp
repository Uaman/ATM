//Developed by Dima Zvazhii
//08.11.14
#include "MainWindow.h"
#include "MainMenu.h"
#include "ui_MainWindow.h"
#include "MainWindowFrame.h"
//#include "Classes/GUI/MenuStates.h"
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
   //_currentFrame=new MainWindowFrame();
    ui->setupUi(this);

   // _currentFrame->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    MainMenu* m=new MainMenu(ui->frame);
    //ui->frame->~QFrame();
    //ui->setupUi(m);

    m->show();
}

void MainWindow::addSonFrame(QFrame *son)
{
    son->setParent(ui->frame);
    son->show();
}

void MainWindow::on_pushButton_clicked()
{
    emit closeWindow();
}

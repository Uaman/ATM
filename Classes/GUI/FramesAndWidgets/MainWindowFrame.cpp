#include "MainWindowFrame.h"
#include "ui_MainWindowFrame.h"

MainWindowFrame::MainWindowFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MainWindowFrame)
{
    ui->setupUi(this);
}

MainWindowFrame::~MainWindowFrame()
{
    delete ui;
}

void MainWindowFrame::on_pushButton_clicked()
{
    emit signalLogInClicked();
}

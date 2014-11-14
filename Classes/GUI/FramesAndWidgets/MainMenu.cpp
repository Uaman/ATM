//Developed by Dima Zvazhii
//08.11.14
#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_commandLinkButton_clicked()
{
    emit signal_on_pay_clicked();
}

void MainMenu::on_commandLinkButton_4_clicked()
{
    emit singal_balance_on_screen();
}

//sends signal_sending_money signal for
//redirecting to SendingMoney window
void MainMenu::on_commandLinkButton_2_clicked()
{
    emit signal_sending_money();
}

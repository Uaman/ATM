#include "SendingMoneyFrame.h"
#include "ui_SendingMoneyFrame.h"
#include "MyEditLine.h"

SendingMoneyFrame::SendingMoneyFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SendingMoneyFrame),
    _cardNumber(new MyEditLine()),
    _password(new MyEditLine()),
    _flag(true),
    _st("")
{

    _cardNumber->setParent(this);
    _password->setParent(this);
    _password->show();
    _cardNumber->show();
    connect(_cardNumber,&MyEditLine::focused,this,&SendingMoneyFrame::cardLineEditting);
    connect(_password,&MyEditLine::focused,this,&SendingMoneyFrame::passwordLineEditing);
    ui->setupUi(this);
    _cardNumber->move(ui->label_2->x(),ui->label_2->y()+37);
    _password->move(ui->label_3->x(),ui->label_3->y()+30);
    //_cardNumber->setFixedHeight(40);


}

void SendingMoneyFrame::doSmth()
{
    //ui->label_3->setText("HELLLLO");
}

void SendingMoneyFrame::editLine()
{
    if(_flag==true)
    {
        _cardNumber->insert(_st);
    }else _password->insert(_st);
}

void SendingMoneyFrame::passwordLineEditing()
{
    _flag=false;
}

void SendingMoneyFrame::cardLineEditting()
{
    _flag=true;
}

SendingMoneyFrame::~SendingMoneyFrame()
{
    delete ui;
}


//press 1
void SendingMoneyFrame::on_pushButton_2_clicked()
{
    _st="1";
    editLine();
}

void SendingMoneyFrame::on_commandLinkButton_clicked()
{
    emit backToMainMenu();
}

//press 2
void SendingMoneyFrame::on_pushButton_3_clicked()
{
    _st="2";
    editLine();
}


//press 3
void SendingMoneyFrame::on_pushButton_5_clicked()
{
    _st="3";
    editLine();
}


//press 4
void SendingMoneyFrame::on_pushButton_4_clicked()
{
    _st="4";
    editLine();
}

//press 5
void SendingMoneyFrame::on_pushButton_6_clicked()
{
    _st="5";
    editLine();
}

//press 6
void SendingMoneyFrame::on_pushButton_7_clicked()
{
    _st="6";
    editLine();
}

//press 7
void SendingMoneyFrame::on_pushButton_8_clicked()
{
    _st="7";
    editLine();
}

//press 8
void SendingMoneyFrame::on_pushButton_9_clicked()
{
    _st="8";
    editLine();
}

//press 9
void SendingMoneyFrame::on_pushButton_10_clicked()
{
    _st="9";
    editLine();
}


//press 0
void SendingMoneyFrame::on_pushButton_13_clicked()
{
    _st="0";
    editLine();
}

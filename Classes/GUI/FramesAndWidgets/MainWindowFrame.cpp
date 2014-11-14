//Developed by Dima Zvazhii
//08.11.14
#include "MainWindowFrame.h"
#include "ui_MainWindowFrame.h"
#include "MyEditLine.h"


MainWindowFrame::MainWindowFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MainWindowFrame),
    _cardLine(new MyEditLine()),
    _passLine(new MyEditLine()),
    _st(""),
    _flag(true)
{
    _cardLine->setParent(this);
    _passLine->setParent(this);
    _passLine->show();
    _cardLine->show();
    connect(_cardLine,&MyEditLine::focused,this,&MainWindowFrame::editingCardLine);
    connect(_passLine,&MyEditLine::focused,this,&MainWindowFrame::editingPassLine);
    connect(_cardLine,SIGNAL(editingFinished()),SLOT(on_lineEdit_editingFinished()));
    connect(_passLine,SIGNAL(editingFinished()),SLOT(on_lineEdit_2_editingFinished()));
    ui->setupUi(this);
    _cardLine->move(ui->label_2->x(),ui->label_2->y()+37);
    _passLine->move(ui->label_3->x(),ui->label_3->y()+30);
    _passLine->setEchoMode(QLineEdit::EchoMode::Password);
}

void MainWindowFrame::edittingLine()
{
    if(_flag==true)
    {
        _cardLine->insert(_st);
    }else _passLine->insert(_st);
}

void MainWindowFrame::editingCardLine()
{
    _flag=true;
}

void MainWindowFrame::editingPassLine()
{
    _flag=false;
}

MainWindowFrame::~MainWindowFrame()
{
    delete ui;
}

void MainWindowFrame::on_pushButton_clicked()
{
    emit signalLogInClicked();
}

const QString& MainWindowFrame::getCardNumber() const
{
    return _cardNumb;
}

const QString& MainWindowFrame::getPassword() const
{
    return _pass;
}

void MainWindowFrame::on_lineEdit_editingFinished()
{
    _cardNumb=_cardLine->text();
    emit loginEntered();
}

void MainWindowFrame::on_lineEdit_2_editingFinished()
{
    _pass=_passLine->text();
    emit passwordEntered();
}


//press 1
void MainWindowFrame::on_pushButton_2_clicked()
{
    _st="1";
    edittingLine();
}


//press 2
void MainWindowFrame::on_pushButton_3_clicked()
{
    _st="2";
    edittingLine();
}

//press 3
void MainWindowFrame::on_pushButton_5_clicked()
{
    _st="3";
    edittingLine();
}

//press 4
void MainWindowFrame::on_pushButton_4_clicked()
{
    _st="4";
    edittingLine();
}


//press 5
void MainWindowFrame::on_pushButton_6_clicked()
{
    _st="5";
    edittingLine();
}

//press 6
void MainWindowFrame::on_pushButton_7_clicked()
{
    _st="6";
    edittingLine();
}

//press 7
void MainWindowFrame::on_pushButton_8_clicked()
{
    _st="7";
    edittingLine();
}

//press 8
void MainWindowFrame::on_pushButton_9_clicked()
{
    _st="8";
    edittingLine();
}

//press 9
void MainWindowFrame::on_pushButton_10_clicked()
{
    _st="9";
    edittingLine();
}

//press 0
void MainWindowFrame::on_pushButton_13_clicked()
{
    _st="0";
    edittingLine();
}


//press <-
void MainWindowFrame::on_pushButton_11_clicked()
{
    MyEditLine* worker=nullptr;
    if(_flag==true)
    {
        worker=_cardLine;
    }else worker=_passLine;
    QString string=worker->text();
    string.chop(1);
    worker->setText(string);
    worker=0;
}

void MainWindowFrame::on_pushButton_12_clicked()
{
    if(_flag==true)
    {
        _cardLine->setText("");
    }else _passLine->setText("");
}

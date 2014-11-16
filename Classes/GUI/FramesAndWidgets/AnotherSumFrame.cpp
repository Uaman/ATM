//Developed by Dima Zvazhii
//08.11.14
#include "AnotherSumFrame.h"
#include "ui_AnotherSumFrame.h"

AnotherSumFrame::AnotherSumFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AnotherSumFrame)
{
    ui->setupUi(this);
}



AnotherSumFrame::~AnotherSumFrame()
{
    delete ui;
}

//emits singal for going back on TakingMoneyWindow
void AnotherSumFrame::on_commandLinkButton_clicked()
{
    emit signalBackOnTackingMoneyFrame();
}

//press 1
void AnotherSumFrame::on_pushButton_2_clicked()
{
    ui->lineEdit->insert("1");
}

//press 2
void AnotherSumFrame::on_pushButton_3_clicked()
{
    ui->lineEdit->insert("2");
}

//press 3
void AnotherSumFrame::on_pushButton_5_clicked()
{
    ui->lineEdit->insert("3");
}

//press 4
void AnotherSumFrame::on_pushButton_4_clicked()
{
    ui->lineEdit->insert("4");
}

//press 5
void AnotherSumFrame::on_pushButton_6_clicked()
{
     ui->lineEdit->insert("5");
}

//press 6
void AnotherSumFrame::on_pushButton_7_clicked()
{
    ui->lineEdit->insert("6");
}

//press 7
void AnotherSumFrame::on_pushButton_8_clicked()
{
     ui->lineEdit->insert("7");
}

//press 8
void AnotherSumFrame::on_pushButton_9_clicked()
{
    ui->lineEdit->insert("8");
}

//press 9
void AnotherSumFrame::on_pushButton_10_clicked()
{
    ui->lineEdit->insert("9");
}

//press 0
void AnotherSumFrame::on_pushButton_13_clicked()
{
    ui->lineEdit->insert("0");
}

//press <-
void AnotherSumFrame::on_pushButton_11_clicked()
{
    QString st=ui->lineEdit->text();
    st.chop(1);
    ui->lineEdit->setText(st);
}

void AnotherSumFrame::on_pushButton_12_clicked()
{
    ui->lineEdit->setText("");
}

//getting money from line edit
const int AnotherSumFrame::getMoneyFromLine() const
{
    return ui->lineEdit->text().toInt();
}

void AnotherSumFrame::on_pushButton_clicked()
{
    emit takeAnotherSum();
}

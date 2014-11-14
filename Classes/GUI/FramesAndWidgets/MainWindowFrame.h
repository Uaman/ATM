//Developed by Dima Zvazhii
//08.11.14
#ifndef MAINWINDOWFRAME_H
#define MAINWINDOWFRAME_H

#include <QFrame>
#include "MyEditLine.h"

namespace Ui {
class MainWindowFrame;
}

class MainWindowFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MainWindowFrame(QWidget *parent = 0);
    ~MainWindowFrame();
    const QString &getCardNumber()const;
    const QString &getPassword()const;
signals:
    void signalLogInClicked(void);
    void loginEntered(void);
    void passwordEntered(void);
public slots:
    void on_pushButton_clicked();
private slots:
    void edittingLine();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void editingCardLine();

    void editingPassLine();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindowFrame *ui;
    QString _cardNumb;
    QString _pass;
    MyEditLine* _cardLine;
    MyEditLine* _passLine;
    //what line is editting
    bool _flag;
    QString _st;
};

#endif // MAINWINDOWFRAME_H

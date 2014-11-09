//Developed by Dima Zvazhii
//08.11.14
#ifndef MAINWINDOWFRAME_H
#define MAINWINDOWFRAME_H

#include <QFrame>

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
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::MainWindowFrame *ui;
    QString _cardNumb;
    QString _pass;
};

#endif // MAINWINDOWFRAME_H

//Developed by Dima Zvazhii
//08.11.14
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void addSonFrame(QFrame*);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    //QFrame* _currentFrame;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

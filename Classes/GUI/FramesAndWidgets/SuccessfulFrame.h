#ifndef SUCCESSFULFRAME_H
#define SUCCESSFULFRAME_H

#include <QFrame>

namespace Ui {
class SuccessfulFrame;
}

class SuccessfulFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SuccessfulFrame(QWidget *parent = 0);
    ~SuccessfulFrame();

private:
    Ui::SuccessfulFrame *ui;
};

#endif // SUCCESSFULFRAME_H

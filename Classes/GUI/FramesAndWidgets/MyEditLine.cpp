#include "MyEditLine.h"
#include <QFocusEvent>

MyEditLine::MyEditLine(QWidget *parent) :
    QLineEdit(parent)
{
    return;
}

void MyEditLine::focusInEvent(QFocusEvent *e)
{
    if (e->reason() == Qt::MouseFocusReason)
        {
          emit focused();
        }

        // You might also call the parent method.
        //QLineEdit::focusInEvent(e);
}

void MyEditLine::focusOutEvent(QFocusEvent *e)
{
  QLineEdit::focusOutEvent(e);
  //emit(focussed(false));
}

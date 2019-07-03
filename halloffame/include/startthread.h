#ifndef STARTTHREAD_H
#define STARTTHREAD_H

#include <QThread>
#include "widget.h"

class Widget ;

class StartThread : public QThread
{
    Q_OBJECT

public:
    explicit StartThread(Widget& mo_widget);
    ~StartThread() {}

    Widget& mo_widget;

    void run();

signals:
    void sigHideAll();
};

#endif // STARTTHREAD_H

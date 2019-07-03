#ifndef ZHOU_H
#define ZHOU_H

#include <QThread>

#include "widget.h"

class Widget ;

class Zhou : public QThread
{
    Q_OBJECT

public:
    explicit Zhou(Widget& mo_widget);
    ~Zhou() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // ZHOU_H

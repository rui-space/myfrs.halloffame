#ifndef YUAN_H
#define YUAN_H

#include <QThread>

#include "widget.h"

class Widget ;

class Yuan : public QThread
{
    Q_OBJECT

public:
    explicit Yuan(Widget& mo_widget);
    ~Yuan() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // YUAN_H

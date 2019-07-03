#ifndef YUE_H
#define YUE_H

#include <QThread>

#include "widget.h"

class Widget ;

class Yue : public QThread
{
    Q_OBJECT

public:
    explicit Yue(Widget& mo_widget);
    ~Yue() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // YUE_H

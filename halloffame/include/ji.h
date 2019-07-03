#ifndef JI_H
#define JI_H

#include <QThread>

#include "widget.h"

class Widget ;

class Ji : public QThread
{
    Q_OBJECT

public:
    explicit Ji(Widget& mo_widget);
    ~Ji() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // JI_H

#ifndef KUANG_H
#define KUANG_H

#include <QThread>

#include "widget.h"

class Widget ;

class Kuang : public QThread
{
    Q_OBJECT

public:
    explicit Kuang(Widget& mo_widget);
    ~Kuang() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // KUANG_H

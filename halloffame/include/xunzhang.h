#ifndef XUNZHANG_H
#define XUNZHANG_H

#include <QThread>

#include "widget.h"

class Widget ;

class XunZhang : public QThread
{
    Q_OBJECT

public:
    explicit XunZhang(Widget& mo_widget);
    ~XunZhang() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // XUNZHANG_H

#ifndef FAGUANG_H
#define FAGUANG_H

#include <QThread>

#include "widget.h"

class Widget ;

class FaGuang : public QThread
{
    Q_OBJECT

public:
    explicit FaGuang(Widget& mo_widget);
    ~FaGuang() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // FAGUANG_H

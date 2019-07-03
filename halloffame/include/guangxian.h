#ifndef GUANGXIAN_H
#define GUANGXIAN_H

#include <QThread>

#include "widget.h"

class Widget ;

class GuangXian : public QThread
{
    Q_OBJECT

public:
    explicit GuangXian(Widget& mo_widget);
    ~GuangXian() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // GUANGXIAN_H

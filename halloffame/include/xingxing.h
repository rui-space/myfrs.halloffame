#ifndef XINGXING_H
#define XINGXING_H

#include <QThread>

#include "widget.h"

class Widget ;

class XingXing : public QThread
{
    Q_OBJECT

public:
    explicit XingXing(Widget& mo_widget);
    ~XingXing() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // XINGXING_H

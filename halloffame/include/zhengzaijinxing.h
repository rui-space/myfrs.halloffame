#ifndef ZHENGZAIJINXING_H
#define ZHENGZAIJINXING_H

#include <QThread>

#include "widget.h"

class Widget ;

class ZhengZaiJinXing : public QThread
{
    Q_OBJECT

public:
    explicit ZhengZaiJinXing(Widget& mo_widget);
    ~ZhengZaiJinXing() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // ZHENGZAIJINXING_H

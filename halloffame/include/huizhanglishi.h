#ifndef HUIZHANGLISHI_H
#define HUIZHANGLISHI_H

#include <QThread>

#include "widget.h"

class Widget ;

class HuiZhangLiShi : public QThread
{
    Q_OBJECT

public:
    explicit HuiZhangLiShi(Widget& mo_widget);
    ~HuiZhangLiShi() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // HUIZHANGLISHI_H

#ifndef YUANGUANG_H
#define YUANGUANG_H

#include <QThread>

#include "widget.h"

class Widget ;

class YuanGuang : public QThread
{
    Q_OBJECT

public:
    explicit YuanGuang(Widget& mo_widget);
    ~YuanGuang() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // YUANGUANG_H

#ifndef MINGRENTANG_H
#define MINGRENTANG_H

#include <QThread>

#include "widget.h"

class Widget ;

class MingRenTang : public QThread
{
    Q_OBJECT

public:
    explicit MingRenTang(Widget& mo_widget);
    ~MingRenTang() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // MINGRENTANG_H

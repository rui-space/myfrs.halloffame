#ifndef QIEHUANTOUXIANG_H
#define QIEHUANTOUXIANG_H

#include <QThread>

#include "widget.h"

class Widget ;

class QieHuanTouXiang : public QThread
{
    Q_OBJECT

public:
    explicit QieHuanTouXiang(Widget& mo_widget);
    ~QieHuanTouXiang() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int i = 0 );
};

#endif // QIEHUANTOUXIANG_H

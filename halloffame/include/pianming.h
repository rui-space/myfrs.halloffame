#ifndef PIANMING_H
#define PIANMING_H

#include <QThread>

#include "widget.h"

class Widget ;

class PianMing : public QThread
{
    Q_OBJECT

public:
    explicit PianMing(Widget& mo_widget);
    ~PianMing() {}

    static const int max_pic_size ;
    Widget& mo_widget;

    void run();

signals:
    void sigShow(const int);
};

#endif // PIANMING_H

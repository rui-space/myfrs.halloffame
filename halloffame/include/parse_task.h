#ifndef _PARSE_TASK_H_
#define _PARSE_TASK_H_

#include <QObject>
#include <memory>
#include <string>

#include "threadpool.h"
#include "task.h"
#include "widget.h"

class Widget ;

class parse_task : public QObject, public rui::threadtask
{
    Q_OBJECT

public:
    explicit parse_task( std::shared_ptr<rui::task> p_task, Widget& o) ;
    ~parse_task() {}

    virtual void run( );

    std::shared_ptr<rui::task> mp_task ;
    Widget& mo_widget;

signals:
    void sigGameStart(const int i_session_id=-1);
    void sigGameOver();
};

#endif


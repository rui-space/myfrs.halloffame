#ifndef	_READ_TASK_H_
#define	_READ_TASK_H_

#include <memory>
#include <QObject>
#include "threadpool.h"
#include "task.h"
#include "widget.h"

class Widget ;

class read_task : public QObject, public rui::threadtask
{
    Q_OBJECT

public:
    explicit read_task( std::shared_ptr<rui::task> p_task, Widget& o );
    ~read_task() {}

    virtual void run();

    std::shared_ptr<rui::task> mp_task ;
    Widget& mo_widget;
};

#endif

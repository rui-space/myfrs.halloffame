#ifndef _MAIN_SERVICE_H_
#define _MAIN_SERVICE_H_

#include <QObject>
#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <map>

#include "epoll.h"
#include "task.h"
#include "widget.h"

class Widget ;

extern int gi_client_idle ;

class main_service : public QObject
{
    Q_OBJECT

private:
    explicit main_service(Widget& o) ;
    ~main_service() ;

    main_service(const main_service&);
    main_service& operator=(const main_service&);

    void add_task(const int i_socket ) ;
    void del_task(const int i_socket);

    static void* epoll_accept_routine(void* arg) ;
    void epoll_accept_entry(void);

    static void* epoll_wait_routine(void* arg) ;
    void epoll_wait_entry(void);

    static void* epoll_clear_routine(void* arg) ;
    void epoll_clear_entry(void);

    rui::epoll mservice_epoll ;
    bool b_quit;

    std::map<int, std::shared_ptr<rui::task>> mm_task ;

public:
    static main_service& _instance(Widget& o){
        static main_service instance(o) ;
        return instance ;
    }

    bool start(void) ;
    void del_task(std::shared_ptr<rui::task> p_task) ;

    Widget& mo_widget;
} ;

#endif


#include "widget.h"
#include <QApplication>

#include "rui.h"
#include "main_service.h"
#include "threadpool.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/wait.h>

#include <string>
#include <iostream>
#include "main.h"

config g_config ;

int main(int argc, char *argv[])
{
    if (argc >= 2 )
        QDir::setCurrent(argv[1]);

    if ( !g_config.get() ) {
        rlog << "g_config.get() error" << std::endl ;
        return -1;
    }

    QApplication a(argc, argv);
    Widget w;
    w.show();

    if ( !rui::threadpool::_instance().start() )
    {
        rlog << "rui::threadpool::_instance().start() error" << std::endl ;
        return -1 ;
    }
    rlog << "threadpool start success" << std::endl ;

    if ( !main_service::_instance(w).start() )
    {
        rlog << "main_service::_instance().start() error" << std::endl ;
        return -1;
    }
    rlog << "main_service start success" << std::endl ;

    return a.exec();
}

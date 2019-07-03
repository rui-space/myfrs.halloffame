#include "faguang.h"

const int FaGuang::max_pic_size = 19;

FaGuang::FaGuang(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(faguangShowSlot(const int)) );
}

void FaGuang::run() {
    int i = 0 ;

    while(true) {
        emit sigShow(i);

        if ( i >= max_pic_size )
            break;
        i++;

        QThread::msleep(100);
    }
}

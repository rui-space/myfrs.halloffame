#include "mingrentang.h"

const int MingRenTang::max_pic_size = 25;

MingRenTang::MingRenTang(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(mingrentangShowSlot(const int)) );
}

void MingRenTang::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    int i = 0 ;
    while(true) {
        emit sigShow(i);

        if ( i >= max_pic_size )
            break;
        i++;

        QThread::msleep(100);
    }
}

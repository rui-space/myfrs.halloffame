#include "kuang.h"

const int Kuang::max_pic_size = 10;

Kuang::Kuang(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(kuangShowSlot(const int)) );
}

void Kuang::run(){
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

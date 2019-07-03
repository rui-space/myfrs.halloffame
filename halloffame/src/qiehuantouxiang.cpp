#include "qiehuantouxiang.h"

const int QieHuanTouXiang::max_pic_size = 28;

QieHuanTouXiang::QieHuanTouXiang(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(qiehuantouxiangShowSlot(const int)) );
}

void QieHuanTouXiang::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    int i = 0 ;
    while(true) {
        emit sigShow(i);

        if ( i >= max_pic_size+1 )
            break;
        i++;

        QThread::msleep(120);
    }
}

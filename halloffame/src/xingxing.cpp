#include "xingxing.h"

const int XingXing::max_pic_size = 46;

XingXing::XingXing(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(xingxingShowSlot(const int)) );
}

void XingXing::run(){
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

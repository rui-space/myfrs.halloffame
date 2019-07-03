#include "pianming.h"

const int PianMing::max_pic_size =20;

PianMing::PianMing(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(pianmingShowSlot(const int)) );
}

void PianMing::run() {
    int i = 0 ;

    while(true) {
        emit sigShow(i);

        i++;
        if ( i > max_pic_size )
            break;

        QThread::msleep(60);
    }
}

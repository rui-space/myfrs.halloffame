#include "guangxian.h"

const int GuangXian::max_pic_size =0;

GuangXian::GuangXian(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(guangxianShowSlot(const int)) );
}

void GuangXian::run() {
    int i = 0 ;

    while(true) {
        emit sigShow(i);

        i++ ;
        if ( i > 60000) i=0;
        QThread::msleep(60);
    }
}

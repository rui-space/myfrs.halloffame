#include "zhou.h"

const int Zhou::max_pic_size = 9;

Zhou::Zhou(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(zhouShowSlot(const int)) );
}

void Zhou::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    emit sigShow(0);
}

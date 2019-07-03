#include "yue.h"

const int Yue::max_pic_size = 0;

Yue::Yue(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(yueShowSlot(const int)) );
}

void Yue::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    emit sigShow(0);
}

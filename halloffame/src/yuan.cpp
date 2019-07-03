#include "yuan.h"

const int Yuan::max_pic_size = 0;

Yuan::Yuan(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(yuanShowSlot(const int)) );
}

void Yuan::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    emit sigShow(0);
}

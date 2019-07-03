#include "ji.h"

const int Ji::max_pic_size = 0;

Ji::Ji(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(jiShowSlot(const int)) );
}

void Ji::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    emit sigShow(0);
}

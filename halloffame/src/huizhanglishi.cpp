#include "huizhanglishi.h"

const int HuiZhangLiShi::max_pic_size = 9;

HuiZhangLiShi::HuiZhangLiShi(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(huizhanglishiShowSlot(const int)) );
}

void HuiZhangLiShi::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif


    emit sigShow(0);
}

#include "zhengzaijinxing.h"

const int ZhengZaiJinXing::max_pic_size = 0;

ZhengZaiJinXing::ZhengZaiJinXing(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(zhengzaijinxingShowSlot(const int)) );
}

void ZhengZaiJinXing::run(){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    emit sigShow(0);
}

#include "xunzhang.h"

const int XunZhang::max_pic_size =0;

XunZhang::XunZhang(Widget& o) : mo_widget(o)
{
    connect( this, SIGNAL(sigShow(const int)), &mo_widget, SLOT(xunzhangShowSlot(const int)) );
}

void XunZhang::run() {
    emit sigShow(0);
}

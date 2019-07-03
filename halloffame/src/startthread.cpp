#include "startthread.h"

StartThread::StartThread(Widget& o) : mo_widget(o) {
    connect(this, SIGNAL(sigHideAll()), &mo_widget, SLOT(hideAllSlot()));
}

void StartThread::run() {

    emit sigHideAll();

    //实时刷新周月季数据库
    mo_widget.historyThread->start();

    //游戏监听事件
    mo_widget.currentThread->start();
}

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>
#include <QMutex>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <thread>
#include <QString>
#include <QUdpSocket>
#include <atomic>
#include "faguang.h"
#include "guangxian.h"
#include "xingxing.h"
#include "xunzhang.h"
#include "mingrentang.h"
#include "zhengzaijinxing.h"
#include "huizhanglishi.h"
#include "zhou.h"
#include "yue.h"
#include "ji.h"
#include "kuang.h"
#include "yuan.h"
#include "yuanguang.h"
#include "qiehuantouxiang.h"
#include "pianming.h"

#include "currentthread.h"
#include "historythread.h"
#include "startthread.h"

#include "lock.h"

#define DEBUG_INFO 0

const int JIN = 0 ;
const int YIN = 1 ;
const int TONG = 2;

const int RUNNING = 0;
const int OVER = 1;
const int ZHOU = 2;
const int YUE = 3;
const int JI = 4;

extern pthread_mutex_t mylock;

class FaGuang;
class GuangXian;
class XingXing;
class XunZhang;
class MingRenTang;

class ZhengZaiJinXing;
class HuiZhangLiShi;
class Zhou;
class Yue;
class Ji;

class Kuang;
class Yuan;
class YuanGuang;

class QieHuanTouXiang;

class PianMing;

class HistoryThread;
class CurrentThread;
class StartThread;

bool downloadPic(const std::string& s_player_avatar, std::string& file) ;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    std::atomic<int> game_state{-1} ;

public:
    QGraphicsOpacityEffect effectPianMing;
    QGraphicsOpacityEffect effectKuangJin;
    QGraphicsOpacityEffect effectKuangYin;
    QGraphicsOpacityEffect effectKuangTong;
    QGraphicsOpacityEffect effectKuangXiaJin;
    QGraphicsOpacityEffect effectKuangXiaYin;
    QGraphicsOpacityEffect effectKuangXiaTong;

    QTime gameOverTime;

    FaGuang* faguangThread;
    GuangXian* guangxianThread;
    XingXing* xingxingThread;
    XunZhang* xunzhangThread;
    MingRenTang* mingrentangThread;

    ZhengZaiJinXing* zhengzaijinxingThread;
    HuiZhangLiShi* huizhanglishiThread;
    Zhou* zhouThread;
    Yue* yueThread;
    Ji* jiThread;

    Kuang* kuangThread;
    Yuan* yuanThread;
    YuanGuang* yuanguangThread;

    QieHuanTouXiang* qiehuantouxiangThread;

    PianMing* pianmingThread;

    HistoryThread* historyThread;
    CurrentThread* currentThread;
    StartThread* startThread;

    void locateComponents();
    int getGameState() ;
    void setGameState(const int i=0) ;

public slots:
    void udpBind();

    void hideAllSlot();

    void faguangShowSlot(const int i = 0);
    void guangxianShowSlot(const int i = 0);
    void xingxingShowSlot(const int i = 0);
    void xunzhangShowSlot(const int i = 0);
    void pianmingShowSlot(const int i = 0) ;
    void mingrentangShowSlot(const int i = 0);
    void zhengzaijinxingShowSlot(const int i = 0) ;
    void huizhanglishiShowSlot(const int i = 0) ;
    void zhouShowSlot(const int i = 0) ;
    void yueShowSlot(const int i = 0) ;
    void jiShowSlot(const int i = 0) ;
    void yuanShowSlot(const int i = 0) ;
    void yuanguangShowSlot(const int i = 0) ;
    void kuangShowSlot(const int i = 0) ;
    void qiehuantouxiangShowSlot(const int i = 0) ;
    void touxiangShowSlot(const int rank=0, const QPixmap& pic=QPixmap("")) ;
    void shuziShowSlot(const int rank=0, const QString& score="") ;
};

#endif // WIDGET_H

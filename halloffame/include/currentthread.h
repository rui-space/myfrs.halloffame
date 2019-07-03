#ifndef CURRENTTHREAD_H
#define CURRENTTHREAD_H

#include <QThread>
#include <QtSql>

#include "widget.h"

class Widget ;

class CurrentThread : public QThread
{
    Q_OBJECT

public:
    explicit CurrentThread(Widget& mo_widget);
    ~CurrentThread();

    Widget& mo_widget;
    QUdpSocket mSocket;
    QSqlDatabase db ;

    int mi_session_id;

    uint32_t rank1_seat;
    uint32_t rank2_seat;
    uint32_t rank3_seat;

    uint32_t score_prev1;
    uint32_t score_prev2;
    uint32_t score_prev3;

    //运行过程中，每100毫秒刷新一次分数
    QTime runtime;

    //判断游戏是否启动过
    bool isGameHasStarted;
    bool b_is_db_connected ;

    void run();
    bool connect_db() ;

    void stateToggle();
    void touxiangToggle(const int rank=0, const int seat_id=0);

signals:
    void udpBind() ;
    void sigHideAll() ;
    void sigTouxiangShow(const int rank=0, const QPixmap& pic=QPixmap(""));
    void sigShuziShow(const int rank=0, const QString& score="");

public slots:
    void gameStartSlot(const int i_session_id=-1);
    void gameOverSlot();
    void getScore();
};

#endif // CURRENTTHREAD_H

#include "rui.h"
#include "currentthread.h"
#include "Common.pb.h"
#include <QDebug>
#include <iostream>
#include "main.h"

CurrentThread::CurrentThread(Widget& o) : mo_widget(o),
    mi_session_id(-1),
    rank1_seat(0),
    rank2_seat(0),
    rank3_seat(0),

    score_prev1(0),
    score_prev2(0),
    score_prev3(0),

    isGameHasStarted(false),
    b_is_db_connected(false)
{
    connect(this, SIGNAL(udpBind()), &mo_widget, SLOT(udpBind()));
    connect(this, SIGNAL(sigHideAll()), &mo_widget, SLOT(hideAllSlot()));
    connect(&mSocket, SIGNAL(readyRead()), this, SLOT(getScore()));
    connect(this, SIGNAL(sigTouxiangShow(const int, const QPixmap&)),
            &mo_widget, SLOT(touxiangShowSlot(const int, const QPixmap&)));
    connect( this, SIGNAL(sigShuziShow(const int, const QString&)),
             &mo_widget, SLOT(shuziShowSlot(const int, const QString&)));
}

CurrentThread::~CurrentThread() {
    mSocket.close();

    QSqlDatabase::removeDatabase("current");
    db.close() ;
}



void CurrentThread::gameStartSlot(const int i_session_id) {
    rlog << "------- Game [START] -------" << std::endl;

    rui::mutex lock(mylock);
    mi_session_id = i_session_id ;

    rank1_seat = -1 ;
    rank2_seat = -1 ;
    rank3_seat = -1 ;

    score_prev1 = -1 ;
    score_prev2 = -1 ;
    score_prev3 = -1 ;

    mo_widget.setGameState(RUNNING);
    //切换到正在进行状态
    stateToggle();
    runtime.start();

    isGameHasStarted = true ;
}

void CurrentThread::gameOverSlot() {
    rlog << "------- Game [OVER] -------" << std::endl;

    rui::mutex lock(mylock);

    //只有游戏启动过，才有游戏结束事件，才会等待。
    if ( isGameHasStarted ) {
        mo_widget.setGameState(JI);
        mo_widget.gameOverTime.start();
    }
}

void CurrentThread::run() {
#if DEBUG_INFO
    rlog << "-----------------------" << std::endl;
#endif
    emit udpBind();
}

bool CurrentThread::connect_db() {
#if DEBUG_INFO
    rlog << std::endl;
#endif

    if(b_is_db_connected)
        return true;

    db = QSqlDatabase::addDatabase("QMYSQL", "current");
    db.setHostName(g_config.host.c_str());
    db.setPort(g_config.port);
    db.setUserName(g_config.user.c_str());
    db.setPassword(g_config.password.c_str());
    db.setDatabaseName(g_config.database.c_str());

    if(!db.open()) {
        rlog << "connect database current error" << std::endl;
        b_is_db_connected = false ;
        return false;
    }

    b_is_db_connected = true ;
    rlog << "connect database current success" << std::endl;

    return true ;
}

void CurrentThread::getScore(){
#if DEBUG_INFO
    rlog << std::endl;
#endif

    while(mSocket.hasPendingDatagrams())
    {
        QByteArray byte_data;
        byte_data.resize(static_cast<int>(mSocket.bytesAvailable()));
        mSocket.readDatagram(byte_data.data(), byte_data.size());

        if ( mo_widget.getGameState() != RUNNING )
            return ;

        //超过100毫秒才进行显示
        if ( runtime.elapsed() < 300 ) continue ;
        runtime.start();

        rlog << "score begin <<<<<<<<<<" << std::endl;
        //解析，只需要前三名数据
        std::string strData(byte_data.data(), byte_data.size());
        Common::PlayerScore obj;
        bool isGet = obj.ParseFromString(strData);
        if(!isGet) {
            rlog << "protobuf parse data error !"  << std::endl;
            continue ;
        }

        for(uint32_t seat_index=0; seat_index < uint32_t(obj.values_size()) ; seat_index++ ) {
            const Common::PlayerStats& ps = obj.values(int(seat_index));
            if ( ps.score() != 0 ||
                 ps.rank() != 0 )
            {
                if ( ps.rank() <= 3 && ps.score() != 0 ) {
                    char msg[300] = {0x00};
                    //                    sprintf(msg,"seat_index=%d, score=%d, rank=%d, score_leader=%d, score_follower=%d, accuracy=%f, collectible=%d",
                    //                            seat_index+1, ps.score(), ps.rank(), ps.score_leader(), ps.score_follower(), ps.accuracy(), ps.collectible() );
                    sprintf(msg,"seat_index=%d, score=%d, rank=%d",seat_index+1, ps.score(), ps.rank());
                    rlog << msg << std::endl;
                }
            }

            if( ps.rank() == 1 ){
                if ( score_prev1 != ps.score() ) {
                    score_prev1 = ps.score() ;
                    emit sigShuziShow(1, QString::number(ps.score()));
                }

                if (rank1_seat != seat_index) {
                    rank1_seat = seat_index;
                    touxiangToggle(1, seat_index+1);
                }
            }
            else if (ps.rank() == 2) {
                if ( score_prev2 != ps.score() ) {
                    score_prev2 = ps.score() ;
                    emit sigShuziShow(2, QString::number(ps.score()));
                }

                if (rank2_seat != seat_index) {
                    rank2_seat = seat_index;
                    touxiangToggle(2, seat_index+1);
                }
            }
            else if (ps.rank() == 3) {
                if ( score_prev3 != ps.score() ) {
                    score_prev3 = ps.score() ;
                    emit sigShuziShow(3, QString::number(ps.score()));
                }

                if (rank3_seat != seat_index) {
                    rank3_seat = seat_index;
                    touxiangToggle(3, seat_index+1);
                }
            }
        }

        rlog << ">>>>>>>>>>>>>> score end" << std::endl;
        rlog << std::endl;
    }

}


void CurrentThread::stateToggle() {
    emit sigHideAll();

    //启动正在进行动画
    mo_widget.faguangThread->start();
    mo_widget.guangxianThread->start();
    mo_widget.xingxingThread->start();
    mo_widget.xunzhangThread->start();
    mo_widget.zhengzaijinxingThread->start();
    mo_widget.pianmingThread->start();
    sleep(1);
    mo_widget.kuangThread->start();
    mo_widget.yuanThread->start();
    mo_widget.yuanguangThread->start();
}

void CurrentThread::touxiangToggle(const int rank, const int seat_id) {
    //启动头像切换动画
    mo_widget.qiehuantouxiangThread->start();

    // 连接数据库
    while( !connect_db() )
        sleep(g_config.db_reconnect_interval);

    //获取头像
    QString sql = QString().sprintf(
                "select player_avatar from record where session_id=%d and seat_id=%d and player_avatar is not null",
                mi_session_id,
                seat_id );

    std::string file ;

    QSqlQuery q(sql,db);
    if (!q.next()) {
        rlog << "database current disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    QString s_player_avatar = q.value("player_avatar").toString();
    if ( !downloadPic(s_player_avatar.toStdString(), file) ) {
        rlog << "downloadPic() error"  << std::endl;
        return ;
    }

    //显示头像
    msleep(600);
    std::cout << file << std::endl ;
    emit sigTouxiangShow(rank, QPixmap(file.c_str()));
}

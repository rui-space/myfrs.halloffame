#include "rui.h"
#include "historythread.h"
#include <iostream>
#include "main.h"

HistoryThread::HistoryThread(Widget& o) : mo_widget(o),
    isFirstTime(true),

    picJin(QPixmap("")),
    picYin(QPixmap("")),
    picTong(QPixmap("")),

    scoreJin(""),
    scoreYin(""),
    scoreTong(""),
    b_is_db_connected(false)
{
    connect(this, SIGNAL(sigHideAll()), &mo_widget, SLOT(hideAllSlot()));
    connect(this, SIGNAL(sigTouxiangShow(const int, const QPixmap&)),
            &mo_widget, SLOT(touxiangShowSlot(const int, const QPixmap&)));
    connect( this, SIGNAL(sigShuziShow(const int, const QString&)),
             &mo_widget, SLOT(shuziShowSlot(const int, const QString&)));
}

HistoryThread::~HistoryThread(){
    QSqlDatabase::removeDatabase("history");
    db.close() ;
}

void HistoryThread::run() {
    while(true) {
#if DEBUG_INFO
        rlog << std::endl;
#endif

        if ( !isFirstTime )
            sleep(g_config.history_refresh_interval);
        isFirstTime = false ;

        // 连接数据库
        connect_db();

        scoreJin="";
        scoreYin="";
        scoreTong="";

        rui::mutex lock(mylock);

        switch ( mo_widget.getGameState() ) {
        case RUNNING :
            break;
        case OVER : {
            char msg[100] = {0x00};
            sprintf(msg,"game_state = OVER, game_over_elapsed=%dms", mo_widget.gameOverTime.elapsed() );
            rlog << msg << std::endl;
            if ( mo_widget.gameOverTime.elapsed() < g_config.game_over_wait_interval*1000 )
                break ;

            stateToggle();
            mo_widget.zhouThread->start();
            mo_widget.setGameState(ZHOU);
            getZhouData() ;
            shuziShow();
            touxiangToggle();
            break;
        }
        case ZHOU : {
            stateToggle();
            mo_widget.yueThread->start();
            mo_widget.setGameState(YUE);
            getYueData() ;
            shuziShow();
            touxiangToggle();
            break;
        }
        case YUE : {
            stateToggle();
            mo_widget.jiThread->start();
            mo_widget.setGameState(JI);
            getJiData() ;
            shuziShow();
            touxiangToggle();
            break;
        }
        case JI : {
            stateToggle();
            mo_widget.zhouThread->start();
            mo_widget.setGameState(ZHOU);
            getZhouData() ;
            shuziShow();
            touxiangToggle();
            break;
        }
        default: {
            stateToggle();
            mo_widget.zhouThread->start();
            mo_widget.setGameState(ZHOU);
            getZhouData() ;
            shuziShow();
            touxiangToggle();
            break;
        }
        }
    }
}


void HistoryThread::connect_db() {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    if(b_is_db_connected)
        return ;

    db = QSqlDatabase::addDatabase("QMYSQL", "history");
    db.setHostName(g_config.host.c_str());
    db.setPort(g_config.port);
    db.setUserName(g_config.user.c_str());
    db.setPassword(g_config.password.c_str());
    db.setDatabaseName(g_config.database.c_str());

    if(!db.open()) {
        rlog << "connect database history error" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    b_is_db_connected = true ;
    rlog << "connect database history success" << std::endl ;
}


void HistoryThread::getZhouData(){
    QString sql = QString().sprintf(
                "select player_avatar, player_score from record where session_id in (select id from session where start_time > '%s' and end_time < '%s') order by cast(player_score as signed) desc limit 3",
                getZhouBegin().toLocal8Bit().data(),
                getZhouEnd().toLocal8Bit().data());


    QSqlQuery q(sql,db);

    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreJin = q.value("player_score").toString();
    QString s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picJin.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }

    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreYin = q.value("player_score").toString();
    s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picYin.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }

    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreTong = q.value("player_score").toString();
    s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picTong.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }
}

void HistoryThread::getYueData(){
    QString sql = QString().sprintf(
                "select player_avatar, player_score from record where session_id in (select id from session where start_time > '%s' and end_time < '%s') order by cast(player_score as signed) desc limit 3",
                getYueBegin().toLocal8Bit().data(),
                getYueEnd().toLocal8Bit().data());

    QSqlQuery q(sql,db);

    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreJin = q.value("player_score").toString();
    QString s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picJin.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }
    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreYin = q.value("player_score").toString();
    s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picYin.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }

    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreTong = q.value("player_score").toString();
    s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picTong.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }
}

void HistoryThread::getJiData(){
    QString sql = QString().sprintf(
                "select player_avatar, player_score from record where session_id in (select id from session where start_time > '%s' and end_time < '%s') order by cast(player_score as signed) desc limit 3",
                getJiBegin().toLocal8Bit().data(),
                getJiEnd().toLocal8Bit().data());

    QSqlQuery q(sql,db);
    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreJin = q.value("player_score").toString();
    QString s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picJin.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }

    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreYin = q.value("player_score").toString();
    s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picYin.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }

    if (!q.next()) {
        rlog << "database history disconnected" << std::endl ;
        b_is_db_connected = false ;
        return ;
    }

    scoreTong = q.value("player_score").toString();
    s_player_avatar = q.value("player_avatar").toString();
    if ( !s_player_avatar.isEmpty() ) {
        std::string file ;
        if ( downloadPic(s_player_avatar.toStdString(), file))
            picTong.load(file.c_str());
        else
            rlog << "downloadPic() error" << std::endl ;
    }
}

QString HistoryThread::getZhouBegin() {
    QString sql = "SELECT DATE_FORMAT( SUBDATE(CURDATE(),DATE_FORMAT(CURDATE(),'%w')-1), '%Y-%m-%d 00:00:00') AS '本周一'";
    QSqlQuery q(sql,db);
    if (q.next())
    {
#if DEBUG_INFO
        char msg[100] = {0x00};
        sprintf(msg,"本周一 = %s", q.value(0).toString().toLocal8Bit().toStdString().c_str());
        rlog << msg << std::endl ;
#endif

        return q.value(0).toString();
    }

    return "";
}

QString HistoryThread::getZhouEnd() {
    QString sql = "SELECT DATE_FORMAT( DATE_ADD(SUBDATE(CURDATE(), WEEKDAY(CURDATE())), INTERVAL 6 DAY), '%Y-%m-%d 23:59:59') AS '本周末'";
    QSqlQuery q(sql,db);
    if (q.next())
    {
#if DEBUG_INFO
        char msg[100] = {0x00};
        sprintf(msg,"本周末 = %s", q.value(0).toString().toLocal8Bit().toStdString().c_str());
        rlog << msg << std::endl ;
#endif

        return q.value(0).toString();
    }

    return "";
}

QString HistoryThread::getYueBegin() {
    QString sql = "SELECT DATE_FORMAT( CURDATE(), '%Y-%m-01 00:00:00') AS '本月初'";
    QSqlQuery q(sql,db);
    if (q.next())
    {
#if DEBUG_INFO
        char msg[100] = {0x00};
        sprintf(msg,"本月初 = %s", q.value(0).toString().toLocal8Bit().toStdString().c_str());
        rlog << msg << std::endl ;
#endif

        return q.value(0).toString();
    }

    return "";
}

QString HistoryThread::getYueEnd() {
    QString sql = "SELECT DATE_FORMAT( LAST_DAY(CURDATE()), '%Y-%m-%d 23:59:59') AS '本月末'";
    QSqlQuery q(sql,db);
    if (q.next())
    {
#if DEBUG_INFO
        char msg[100] = {0x00};
        sprintf(msg,"本月末 = %s", q.value(0).toString().toLocal8Bit().toStdString().c_str());
        rlog << msg << std::endl ;
#endif

        return q.value(0).toString();
    }

    return "";
}

QString HistoryThread::getJiBegin() {
    QString sql = "select concat(DATE_FORMAT(LAST_DAY(MAKEDATE(EXTRACT(YEAR FROM CURDATE()),1) + interval QUARTER(CURDATE())*3-3 month),'%Y-%m-'),'01 00:00:00')";
    QSqlQuery q(sql,db);
    if (q.next())
    {
#if DEBUG_INFO
        char msg[100] = {0x00};
        sprintf(msg,"本季初 = %s", q.value(0).toString().toLocal8Bit().toStdString().c_str());
        rlog << msg << std::endl ;
#endif

        return q.value(0).toString();
    }

    return "";
}

QString HistoryThread::getJiEnd() {
    QString sql = "select concat(DATE_FORMAT(LAST_DAY(MAKEDATE(EXTRACT(YEAR FROM CURDATE()),1) + interval QUARTER(CURDATE())*3-1 month),'%Y-%m-%d'),' 23:59:59')";
    QSqlQuery q(sql,db);
    if (q.next())
    {
#if DEBUG_INFO
        char msg[100] = {0x00};
        sprintf(msg,"本季末 = %s", q.value(0).toString().toLocal8Bit().toStdString().c_str());
        rlog << msg << std::endl ;
#endif

        return q.value(0).toString();
    }

    return "";
}

void HistoryThread::stateToggle() {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    emit sigHideAll();

    //启动名人堂动画
    mo_widget.faguangThread->start();
    mo_widget.guangxianThread->start();
    mo_widget.xingxingThread->start();
    mo_widget.xunzhangThread->start();
    mo_widget.mingrentangThread->start();
    mo_widget.pianmingThread->start();
    sleep(1);
    mo_widget.kuangThread->start();
    mo_widget.yuanThread->start();
    mo_widget.yuanguangThread->start();

    //启动“本x"动画
    mo_widget.huizhanglishiThread->start();
}

void HistoryThread::shuziShow() {
    emit sigShuziShow(1, scoreJin);
    emit sigShuziShow(2, scoreYin);
    emit sigShuziShow(3, scoreTong);
}

void HistoryThread::touxiangToggle() {
    //启动头像切换动画
    mo_widget.qiehuantouxiangThread->start();

    //显示头像
    msleep(600);
    emit sigTouxiangShow(1, picJin);
    emit sigTouxiangShow(2, picYin);
    emit sigTouxiangShow(3, picTong);
}

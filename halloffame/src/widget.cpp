#include "rui.h"
#include "widget.h"
#include "ui_widget.h"
#include "main.h"

pthread_mutex_t mylock;

bool downloadPic(const std::string& s_player_avatar, std::string& file ) {
    system("mkdir -p /tmp/halloffame/");

    file = "/tmp/halloffame/" ;
    std::string s_player_avatar_name = s_player_avatar.substr(s_player_avatar.rfind('/')+1, s_player_avatar.length());
    file += s_player_avatar_name;
    {
        std::string cmd = "rm -rvf /tmp/halloffame/" ;
        cmd += file ;
        cmd += "*";
        qDebug() << cmd.c_str() ;
        system(cmd.c_str());
    }

    std::string url = "http://10.10.10.13:8080";
    url += s_player_avatar ;
    std::string cmd = "wget -O /tmp/halloffame/";
    cmd += s_player_avatar_name ;
    cmd += " " ;
    cmd +=  url ;
    qDebug() << cmd.c_str() ;

    int	ret = system( cmd.c_str() ) ;
    if ( WEXITSTATUS( ret ) != 0 ){
        char msg[300] = {0x00};
        sprintf(msg,"download image %s failure", url.c_str());
        std::cout << msg << std::endl ;
        rlog << msg << std::endl ;
        return false;
    }
    return true ;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),

    game_state(-1),

    faguangThread(new FaGuang(*this)),
    guangxianThread(new GuangXian(*this)),
    xingxingThread(new XingXing(*this)),
    xunzhangThread(new XunZhang(*this)),
    mingrentangThread(new MingRenTang(*this)),

    zhengzaijinxingThread(new ZhengZaiJinXing(*this)),
    huizhanglishiThread(new HuiZhangLiShi(*this)),
    zhouThread(new Zhou(*this)),
    yueThread(new Yue(*this)),
    jiThread(new Ji(*this)),

    kuangThread(new Kuang(*this)),
    yuanThread(new Yuan(*this)),
    yuanguangThread(new YuanGuang(*this)),

    qiehuantouxiangThread(new QieHuanTouXiang(*this)),

    pianmingThread(new PianMing(*this)),

    historyThread(new HistoryThread(*this)),
    currentThread(new CurrentThread(*this)),
    startThread(new StartThread(*this))
{
    rlog << std::endl ;
    rlog << std::endl ;
    rlog << std::endl ;
    rlog << "halloffame start !!!!!!" << std::endl ;

    pthread_mutex_init( &mylock, NULL ) ;

    ui->setupUi(this);

    setWindowFlags( Qt::Window | Qt::FramelessWindowHint) ;
    resize(1920,1080 );
    move(0,0);
    showFullScreen();

    locateComponents();

    QUdpSocket socket;
    QByteArray msg = "hello";
    socket.writeDatagram(msg,QHostAddress("10.10.10.11"), g_config.game_event_send_port);

    //后台线程启动
    startThread->start();
}

Widget::~Widget()
{
    delete ui;

    delete faguangThread;
    delete guangxianThread;
    delete xingxingThread;
    delete xunzhangThread;
    delete mingrentangThread;

    delete zhengzaijinxingThread;
    delete huizhanglishiThread;
    delete zhouThread;
    delete yueThread;
    delete jiThread;

    delete kuangThread;
    delete yuanThread;
    delete yuanguangThread;

    delete qiehuantouxiangThread;

    delete pianmingThread;

    delete historyThread;
    delete currentThread;
    delete startThread;

    pthread_mutex_destroy( &mylock ) ;

    rlog << "halloffame quit !!!!!!" << std::endl ;
}

void Widget::udpBind() {
    currentThread->mSocket.bind(QHostAddress::AnyIPv4, g_config.game_event_receive_port);
}

void Widget::hideAllSlot() {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->faguangLabel->hide();
    ui->guangxianLabel->hide();
    ui->xingxingLabel->hide();
    ui->xunzhangLabel->hide();
    ui->pianmingLabel->hide();
    ui->mingrentangLabel->hide();

    ui->zhengzaijinxingLabel->hide();
    ui->huizhanglishiLabel->hide();
    ui->zhouLabel->hide();
    ui->yueLabel->hide();
    ui->jiLabel->hide();

    ui->jinyuanLabel->hide();
    ui->yinyuanLabel->hide();
    ui->tongyuanLabel->hide();

    ui->yuanguangJinLabel->hide();
    ui->yuanguangYinLabel->hide();
    ui->yuanguangTongLabel->hide();

    ui->jinkuangLabel->hide();
    ui->yinkuangLabel->hide();
    ui->tongkuangLabel->hide();

    ui->jinkuangxiaLabel->hide();
    ui->yinkuangxiaLabel->hide();
    ui->tongkuangxiaLabel->hide();

    ui->qiehuantouxiangJinLabel->hide();
    ui->qiehuantouxiangYinLabel->hide();
    ui->qiehuantouxiangTongLabel->hide();

    ui->touxiangJinLabel->setPixmap(QPixmap());
    ui->touxiangYinLabel->setPixmap(QPixmap());
    ui->touxiangTongLabel->setPixmap(QPixmap());

    ui->touxiangJinLabel->hide();
    ui->touxiangYinLabel->hide();
    ui->touxiangTongLabel->hide();

    ui->shuziJin1Label->hide();    //ge
    ui->shuziJin2Label->hide();    //shi
    ui->shuziJin3Label->hide();    //bai
    ui->shuziJin4Label->hide();    //qian
    ui->shuziJin5Label->hide();    //wan
    ui->shuziJin6Label->hide();    //shiwan
    ui->shuziJin7Label->hide();    //baiwan

    ui->shuziYin1Label->hide();    //ge
    ui->shuziYin2Label->hide();    //shi
    ui->shuziYin3Label->hide();    //bai
    ui->shuziYin4Label->hide();    //qian
    ui->shuziYin5Label->hide();    //wan
    ui->shuziYin6Label->hide();    //shiwan
    ui->shuziYin7Label->hide();    //baiwan

    ui->shuziTong1Label->hide();    //ge
    ui->shuziTong2Label->hide();    //shi
    ui->shuziTong3Label->hide();    //bai
    ui->shuziTong4Label->hide();    //qian
    ui->shuziTong5Label->hide();    //wan
    ui->shuziTong6Label->hide();    //shiwan
    ui->shuziTong7Label->hide();    //baiwan
}


void Widget::faguangShowSlot(const int i){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    QString str ;
    if ( i < 10 )
        str.sprintf("ui/faguang/000%d.png",i);
    else
        str.sprintf("ui/faguang/00%d.png",i);

    ui->faguangLabel->setPixmap(QPixmap(str));
    ui->faguangLabel->show();
}

void Widget::guangxianShowSlot(const int i){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    QMatrix matrix;
    matrix.rotate(i);

    ui->guangxianLabel->setPixmap(QPixmap("ui/guangxian.png").transformed(matrix, Qt::SmoothTransformation));
    ui->guangxianLabel->show();
}

void Widget::xingxingShowSlot(const int i){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    QString str ;
    if ( i < 10 )
        str.sprintf("ui/xingxing/000%d.png",i);
    else
        str.sprintf("ui/xingxing/00%d.png",i);

    ui->xingxingLabel->setPixmap(QPixmap(str));
    ui->xingxingLabel->show();
}

void Widget::xunzhangShowSlot(const int){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->xunzhangLabel->show();
}

void Widget::pianmingShowSlot(const int i) {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->pianmingLabel->resize(1920-i*((1920-621)/20),
                                1080-i*((1080-225)/20));
    ui->pianmingLabel->move(i*(657/20),
                              i*(842/20));

    effectPianMing.setOpacity(qreal(i)/qreal(20));
    ui->pianmingLabel->setGraphicsEffect(&effectPianMing);
    ui->pianmingLabel->setWindowOpacity(qreal(i)/qreal(20));
    ui->pianmingLabel->show();
}

void Widget::mingrentangShowSlot(const int i){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    QString str ;
    if ( i < 10 )
        str.sprintf("ui/mingrentang/000%d.png",i);
    else
        str.sprintf("ui/mingrentang/00%d.png",i);

    ui->mingrentangLabel->setPixmap(QPixmap(str));
    ui->mingrentangLabel->show();
}

void Widget::zhengzaijinxingShowSlot(const int){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->zhengzaijinxingLabel->show();
}

void Widget::huizhanglishiShowSlot(const int){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->huizhanglishiLabel->show();
}

void Widget::zhouShowSlot(const int){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->zhouLabel->show();
}

void Widget::yueShowSlot(const int){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->yueLabel->show();
}

void Widget::jiShowSlot(const int){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->jiLabel->show();
}

void Widget::yuanShowSlot(const int){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    ui->jinyuanLabel->show();
    ui->yinyuanLabel->show();
    ui->tongyuanLabel->show();
}

void Widget::yuanguangShowSlot(const int i){
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    QString str ;
    if ( i < 10 )
        str.sprintf("ui/yuanguang/000%d.png",i);
    else
        str.sprintf("ui/yuanguang/00%d.png",i);

    ui->yuanguangJinLabel->setPixmap(QPixmap(str));
    ui->yuanguangYinLabel->setPixmap(QPixmap(str));
    ui->yuanguangTongLabel->setPixmap(QPixmap(str));

    ui->yuanguangJinLabel->show();
    ui->yuanguangYinLabel->show();
    ui->yuanguangTongLabel->show();
}

void Widget::kuangShowSlot(const int i) {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    effectKuangJin.setOpacity(qreal(i)/qreal(10));
    effectKuangYin.setOpacity(qreal(i)/qreal(10));
    effectKuangTong.setOpacity(qreal(i)/qreal(10));
    effectKuangXiaJin.setOpacity(qreal(i)/qreal(10));
    effectKuangXiaYin.setOpacity(qreal(i)/qreal(10));
    effectKuangXiaTong.setOpacity(qreal(i)/qreal(10));

    ui->jinkuangLabel->setGraphicsEffect(&effectKuangJin);
    ui->yinkuangLabel->setGraphicsEffect(&effectKuangYin);
    ui->tongkuangLabel->setGraphicsEffect(&effectKuangTong);
    ui->jinkuangxiaLabel->setGraphicsEffect(&effectKuangXiaJin);
    ui->yinkuangxiaLabel->setGraphicsEffect(&effectKuangXiaYin);
    ui->tongkuangxiaLabel->setGraphicsEffect(&effectKuangXiaTong);

    ui->jinkuangLabel->show();
    ui->yinkuangLabel->show();
    ui->tongkuangLabel->show();
    ui->jinkuangxiaLabel->show();
    ui->yinkuangxiaLabel->show();
    ui->tongkuangxiaLabel->show();
}

void Widget::qiehuantouxiangShowSlot(const int i) {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    QString str ;
    if ( i < 10 )
        str.sprintf("ui/qiehuantouxiang/000%d.png",i);
    else
        str.sprintf("ui/qiehuantouxiang/00%d.png",i);

    ui->qiehuantouxiangJinLabel->setPixmap(QPixmap(str));
    ui->qiehuantouxiangYinLabel->setPixmap(QPixmap(str));
    ui->qiehuantouxiangTongLabel->setPixmap(QPixmap(str));
    ui->qiehuantouxiangJinLabel->show();
    ui->qiehuantouxiangYinLabel->show();
    ui->qiehuantouxiangTongLabel->show();
}

void Widget::touxiangShowSlot(const int rank, const QPixmap& pic) {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    switch ( rank ) {
    case 1: {
        ui->touxiangJinLabel->setPixmap(pic);
        ui->touxiangJinLabel->show();
        break;
    }
    case 2: {
        ui->touxiangYinLabel->setPixmap(pic);
        ui->touxiangYinLabel->show();
        break;
    }
    case 3: {
        ui->touxiangTongLabel->setPixmap(pic);
        ui->touxiangTongLabel->show();
        break;
    }
    }
}

void Widget::shuziShowSlot(const int rank, const QString& score) {
#if DEBUG_INFO
    rlog << std::endl ;
#endif

    if ( score.isEmpty() || score == "0" )
        return ;

    {
        char msg[300] = {0x00};
        sprintf(msg,"rank=%d, score=%s", rank, score.toStdString().c_str() );
        rlog << msg << std::endl ;
    }

    switch(rank) {
    case 1:{
        ui->shuziJin1Label->setPixmap(QPixmap(""));
        ui->shuziJin2Label->setPixmap(QPixmap(""));
        ui->shuziJin3Label->setPixmap(QPixmap(""));
        ui->shuziJin4Label->setPixmap(QPixmap(""));
        ui->shuziJin5Label->setPixmap(QPixmap(""));
        ui->shuziJin6Label->setPixmap(QPixmap(""));
        ui->shuziJin7Label->setPixmap(QPixmap(""));

        if (score.length()>0) {
            QString str = "ui/shuzi/000" ; str += QString(score[0]); str += ".png" ;
            ui->shuziJin1Label->setPixmap(QPixmap(str));
            ui->shuziJin1Label->show();
        }

        if (score.length()>1) {
            QString str = "ui/shuzi/000" ; str += QString(score[1]); str += ".png" ;
            ui->shuziJin2Label->setPixmap(QPixmap(str));
            ui->shuziJin2Label->show();
        }

        if (score.length()>2) {
            QString str = "ui/shuzi/000" ; str += QString(score[2]); str += ".png" ;
            ui->shuziJin3Label->setPixmap(QPixmap(str));
            ui->shuziJin3Label->show();
        }

        if (score.length()>3) {
            QString str = "ui/shuzi/000" ; str += QString(score[3]); str += ".png" ;
            ui->shuziJin4Label->setPixmap(QPixmap(str));
            ui->shuziJin4Label->show();
        }

        if (score.length()>4) {
            QString str = "ui/shuzi/000" ; str += QString(score[4]); str += ".png" ;
            ui->shuziJin5Label->setPixmap(QPixmap(str));
            ui->shuziJin5Label->show();
        }

        if (score.length()>5) {
            QString str = "ui/shuzi/000" ; str += QString(score[5]); str += ".png" ;
            ui->shuziJin6Label->setPixmap(QPixmap(str));
            ui->shuziJin6Label->show();
        }

        if (score.length()>6) {
            QString str = "ui/shuzi/000" ; str += QString(score[6]); str += ".png" ;
            ui->shuziJin7Label->setPixmap(QPixmap(str));
            ui->shuziJin7Label->show();
        }

        break;
    }
    case 2: {
        ui->shuziYin1Label->setPixmap(QPixmap(""));
        ui->shuziYin2Label->setPixmap(QPixmap(""));
        ui->shuziYin3Label->setPixmap(QPixmap(""));
        ui->shuziYin4Label->setPixmap(QPixmap(""));
        ui->shuziYin5Label->setPixmap(QPixmap(""));
        ui->shuziYin6Label->setPixmap(QPixmap(""));
        ui->shuziYin7Label->setPixmap(QPixmap(""));

        if (score.length()>0) {
            QString str = "ui/shuzi/000" ; str += QString(score[0]); str += ".png" ;
            ui->shuziYin1Label->setPixmap(QPixmap(str));
            ui->shuziYin1Label->show();
        }

        if (score.length()>1) {
            QString str = "ui/shuzi/000" ; str += QString(score[1]); str += ".png" ;
            ui->shuziYin2Label->setPixmap(QPixmap(str));
            ui->shuziYin2Label->show();
        }

        if (score.length()>2) {
            QString str = "ui/shuzi/000" ; str += QString(score[2]); str += ".png" ;
            ui->shuziYin3Label->setPixmap(QPixmap(str));
            ui->shuziYin3Label->show();
        }

        if (score.length()>3) {
            QString str = "ui/shuzi/000" ; str += QString(score[3]); str += ".png" ;
            ui->shuziYin4Label->setPixmap(QPixmap(str));
            ui->shuziYin4Label->show();
        }
        if (score.length()>4) {
            QString str = "ui/shuzi/000" ; str += QString(score[4]); str += ".png" ;
            ui->shuziYin5Label->setPixmap(QPixmap(str));
            ui->shuziYin5Label->show();
        }

        if (score.length()>5) {
            QString str = "ui/shuzi/000" ; str += QString(score[5]); str += ".png" ;
            ui->shuziYin6Label->setPixmap(QPixmap(str));
            ui->shuziYin6Label->show();
        }

        if (score.length()>6) {
            QString str = "ui/shuzi/000" ; str += QString(score[6]); str += ".png" ;
            ui->shuziYin7Label->setPixmap(QPixmap(str));
            ui->shuziYin7Label->show();
        }

        break;
    }
    case 3:{
        ui->shuziTong1Label->setPixmap(QPixmap(""));
        ui->shuziTong2Label->setPixmap(QPixmap(""));
        ui->shuziTong3Label->setPixmap(QPixmap(""));
        ui->shuziTong4Label->setPixmap(QPixmap(""));
        ui->shuziTong5Label->setPixmap(QPixmap(""));
        ui->shuziTong6Label->setPixmap(QPixmap(""));
        ui->shuziTong7Label->setPixmap(QPixmap(""));

        if (score.length()>0) {
            QString str = "ui/shuzi/000" ; str += QString(score[0]); str += ".png" ;
            ui->shuziTong1Label->setPixmap(QPixmap(str));
            ui->shuziTong1Label->show();
        }

        if (score.length()>1) {
            QString str = "ui/shuzi/000" ; str += QString(score[1]); str += ".png" ;
            ui->shuziTong2Label->setPixmap(QPixmap(str));
            ui->shuziTong2Label->show();
        }

        if (score.length()>2) {
            QString str = "ui/shuzi/000" ; str += QString(score[2]); str += ".png" ;
            ui->shuziTong3Label->setPixmap(QPixmap(str));
            ui->shuziTong3Label->show();
        }

        if (score.length()>3) {
            QString str = "ui/shuzi/000" ; str += QString(score[3]); str += ".png" ;
            ui->shuziTong4Label->setPixmap(QPixmap(str));
            ui->shuziTong4Label->show();
        }

        if (score.length()>4) {
            QString str = "ui/shuzi/000" ; str += QString(score[4]); str += ".png" ;
            ui->shuziTong5Label->setPixmap(QPixmap(str));
            ui->shuziTong5Label->show();
        }

        if (score.length()>5) {
            QString str = "ui/shuzi/000" ; str += QString(score[5]); str += ".png" ;
            ui->shuziTong6Label->setPixmap(QPixmap(str));
            ui->shuziTong6Label->show();
        }

        if (score.length()>6) {
            QString str = "ui/shuzi/000" ; str += QString(score[6]); str += ".png" ;
            ui->shuziTong7Label->setPixmap(QPixmap(str));
            ui->shuziTong7Label->show();
        }

        break;
    }
    }

}

int Widget::getGameState() {
#if DEBUG_INFO
    switch ( game_state ) {
    case RUNNING : {
        rlog << "game_state == RUNNING" << std::endl ;
        break;
    }
    case OVER : {
        rlog << "game_state == OVER" << std::endl ;
        break;
    }
    case ZHOU : {
        rlog << "game_state == ZHOU" << std::endl ;
        break;
    }
    case YUE : {
        rlog << "game_state == YUE" << std::endl ;
        break;
    }
    case JI : {
        rlog << "game_state == JI" << std::endl ;
        break;
    }
    }
#endif

    return game_state ;
}

void Widget::setGameState(const int i) {
    game_state = i ;

    switch ( game_state ) {
    case RUNNING : {
        rlog << "game_state -> RUNNING" << std::endl ;
        break;
    }
    case OVER : {
        rlog << "game_state -> OVER" << std::endl ;
        break;
    }
    case ZHOU : {
        rlog << "game_state -> ZHOU" << std::endl ;
        break;
    }
    case YUE : {
        rlog << "game_state -> YUE" << std::endl ;
        break;
    }
    case JI : {
        rlog << "game_state -> JI" << std::endl ;
        break;
    }
    }
}

void Widget::locateComponents() {

    ui->backgroundLabel->resize(1920,1080);
    ui->backgroundLabel->move(0,0);
    ui->backgroundLabel->setPixmap(QPixmap("./ui/dituhaibao.png"));
    ui->backgroundLabel->show();

    ui->heizhaoLabel->resize(1920,1080);
    ui->heizhaoLabel->move(0,0);
    ui->heizhaoLabel->setPixmap(QPixmap("./ui/heizhao.png"));
    ui->heizhaoLabel->show();

    ui->faguangLabel->resize(1920,508);
    ui->faguangLabel->move(0,-102);
    ui->faguangLabel->setScaledContents(true);

    ui->guangxianLabel->resize(800,800);
    ui->guangxianLabel->move(560,-250);
    ui->guangxianLabel->setScaledContents(true);

    ui->xingxingLabel->resize(524,373);
    ui->xingxingLabel->move(689,140);
    ui->xingxingLabel->setScaledContents(true);

    ui->xunzhangLabel->resize(522,225);
    ui->xunzhangLabel->move(699,40);
    ui->xunzhangLabel->setScaledContents(true);
    ui->xunzhangLabel->setPixmap(QPixmap("ui/xunzhang.png"));

    ui->mingrentangLabel->resize(314,127);
    ui->mingrentangLabel->move(803,82);
    ui->mingrentangLabel->setScaledContents(true);

    ui->pianmingLabel->setScaledContents(true);
    ui->pianmingLabel->setPixmap(QPixmap("ui/pianming.png"));

    ui->zhengzaijinxingLabel->resize(314,127);
    ui->zhengzaijinxingLabel->move(803,82);
    ui->zhengzaijinxingLabel->setScaledContents(true);
    ui->zhengzaijinxingLabel->setPixmap(QPixmap("ui/zhengzaijinxing.png"));

    ui->huizhanglishiLabel->resize(316,277);
    ui->huizhanglishiLabel->move(1584,20);
    ui->huizhanglishiLabel->setScaledContents(true);
    ui->huizhanglishiLabel->setPixmap(QPixmap("ui/huizhanglishi.png"));

    ui->zhouLabel->resize(201,109);
    ui->zhouLabel->move(1652,104);
    ui->zhouLabel->setScaledContents(true);
    ui->zhouLabel->setPixmap(QPixmap("ui/zhou.png"));

    ui->yueLabel->resize(201,109);
    ui->yueLabel->move(1652,104);
    ui->yueLabel->setScaledContents(true);
    ui->yueLabel->setPixmap(QPixmap("ui/yue.png"));

    ui->jiLabel->resize(201,109);
    ui->jiLabel->move(1652,104);
    ui->jiLabel->setScaledContents(true);
    ui->jiLabel->setPixmap(QPixmap("ui/ji.png"));


    ui->jinyuanLabel->resize(146,146);
    ui->jinyuanLabel->move(716,207);
    ui->jinyuanLabel->setScaledContents(true);
    ui->yinyuanLabel->resize(146,146);
    ui->yinyuanLabel->move(181,287);
    ui->yinyuanLabel->setScaledContents(true);
    ui->tongyuanLabel->resize(146,146);
    ui->tongyuanLabel->move(1251,367);
    ui->tongyuanLabel->setScaledContents(true);
    ui->jinyuanLabel->setPixmap(QPixmap("ui/jinyuan.png"));
    ui->yinyuanLabel->setPixmap(QPixmap("ui/yinyuan.png"));
    ui->tongyuanLabel->setPixmap(QPixmap("ui/tongyuan.png"));


    ui->yuanguangJinLabel->resize(270,258);
    ui->yuanguangJinLabel->move(654,153);
    ui->yuanguangJinLabel->setScaledContents(true);
    ui->yuanguangYinLabel->resize(270,258);
    ui->yuanguangYinLabel->move(119,233);
    ui->yuanguangYinLabel->setScaledContents(true);
    ui->yuanguangTongLabel->resize(270,258);
    ui->yuanguangTongLabel->move(1189,313);
    ui->yuanguangTongLabel->setScaledContents(true);
    ui->jinkuangLabel->resize(342,411);
    ui->jinkuangLabel->move(789,280);
    ui->jinkuangLabel->setScaledContents(true);
    ui->yinkuangLabel->resize(342,411);
    ui->yinkuangLabel->move(254,360);
    ui->yinkuangLabel->setScaledContents(true);
    ui->tongkuangLabel->resize(342,411);
    ui->tongkuangLabel->move(1324,440);
    ui->tongkuangLabel->setScaledContents(true);
    ui->jinkuangxiaLabel->resize(342,111);
    ui->jinkuangxiaLabel->move(789,696);
    ui->jinkuangxiaLabel->setScaledContents(true);
    ui->yinkuangxiaLabel->resize(342,111);
    ui->yinkuangxiaLabel->move(254,776);
    ui->yinkuangxiaLabel->setScaledContents(true);
    ui->tongkuangxiaLabel->resize(342,111);
    ui->tongkuangxiaLabel->move(1324,856);
    ui->tongkuangxiaLabel->setScaledContents(true);
    ui->jinkuangLabel->setPixmap(QPixmap("ui/jinkuang.png"));
    ui->yinkuangLabel->setPixmap(QPixmap("ui/yinkuang.png"));
    ui->tongkuangLabel->setPixmap(QPixmap("ui/tongkuang.png"));
    ui->jinkuangxiaLabel->setPixmap(QPixmap("ui/jinkuangxia.png"));
    ui->yinkuangxiaLabel->setPixmap(QPixmap("ui/yinkuangxia.png"));
    ui->tongkuangxiaLabel->setPixmap(QPixmap("ui/tongkuangxia.png"));


    ui->qiehuantouxiangJinLabel->resize(328,526);
    ui->qiehuantouxiangJinLabel->move(796,260);
    ui->qiehuantouxiangJinLabel->setScaledContents(true);
    ui->qiehuantouxiangYinLabel->resize(328,526);
    ui->qiehuantouxiangYinLabel->move(261,340);
    ui->qiehuantouxiangYinLabel->setScaledContents(true);
    ui->qiehuantouxiangTongLabel->resize(328,526);
    ui->qiehuantouxiangTongLabel->move(1331,420);
    ui->qiehuantouxiangTongLabel->setScaledContents(true);

    ui->touxiangJinLabel->resize(332,401);
    ui->touxiangJinLabel->move(794,285);
    ui->touxiangJinLabel->setScaledContents(true);
    ui->touxiangYinLabel->resize(332,401);
    ui->touxiangYinLabel->move(259,365);
    ui->touxiangYinLabel->setScaledContents(true);
    ui->touxiangTongLabel->resize(332,401);
    ui->touxiangTongLabel->move(1329,445);
    ui->touxiangTongLabel->setScaledContents(true);


    ui->shuziJin1Label->resize(48,55);
    ui->shuziJin1Label->move(813,724);
    ui->shuziJin1Label->setScaledContents(true);
    ui->shuziJin2Label->resize(48,55);
    ui->shuziJin2Label->move(855,724);
    ui->shuziJin2Label->setScaledContents(true);
    ui->shuziJin3Label->resize(48,55);
    ui->shuziJin3Label->move(897,724);
    ui->shuziJin3Label->setScaledContents(true);
    ui->shuziJin4Label->resize(48,55);
    ui->shuziJin4Label->move(939,724);
    ui->shuziJin4Label->setScaledContents(true);
    ui->shuziJin5Label->resize(48,55);
    ui->shuziJin5Label->move(981,724);
    ui->shuziJin5Label->setScaledContents(true);
    ui->shuziJin6Label->resize(48,55);
    ui->shuziJin6Label->move(1023,724);
    ui->shuziJin6Label->setScaledContents(true);
    ui->shuziJin7Label->resize(48,55);
    ui->shuziJin7Label->move(1065,724);
    ui->shuziJin7Label->setScaledContents(true);

    ui->shuziYin1Label->resize(48,55);
    ui->shuziYin1Label->move(278,804);
    ui->shuziYin1Label->setScaledContents(true);
    ui->shuziYin2Label->resize(48,55);
    ui->shuziYin2Label->move(320,804);
    ui->shuziYin2Label->setScaledContents(true);
    ui->shuziYin3Label->resize(48,55);
    ui->shuziYin3Label->move(362,804);
    ui->shuziYin3Label->setScaledContents(true);
    ui->shuziYin4Label->resize(48,55);
    ui->shuziYin4Label->move(404,804);
    ui->shuziYin4Label->setScaledContents(true);
    ui->shuziYin5Label->resize(48,55);
    ui->shuziYin5Label->move(446,804);
    ui->shuziYin5Label->setScaledContents(true);
    ui->shuziYin6Label->resize(48,55);
    ui->shuziYin6Label->move(488,804);
    ui->shuziYin6Label->setScaledContents(true);
    ui->shuziYin7Label->resize(48,55);
    ui->shuziYin7Label->move(530,804);
    ui->shuziYin7Label->setScaledContents(true);

    ui->shuziTong1Label->resize(48,55);
    ui->shuziTong1Label->move(1344,884);
    ui->shuziTong1Label->setScaledContents(true);
    ui->shuziTong2Label->resize(48,55);
    ui->shuziTong2Label->move(1386,884);
    ui->shuziTong2Label->setScaledContents(true);
    ui->shuziTong3Label->resize(48,55);
    ui->shuziTong3Label->move(1428,884);
    ui->shuziTong3Label->setScaledContents(true);
    ui->shuziTong4Label->resize(48,55);
    ui->shuziTong4Label->move(1470,884);
    ui->shuziTong4Label->setScaledContents(true);
    ui->shuziTong5Label->resize(48,55);
    ui->shuziTong5Label->move(1512,884);
    ui->shuziTong5Label->setScaledContents(true);
    ui->shuziTong6Label->resize(48,55);
    ui->shuziTong6Label->move(1554,884);
    ui->shuziTong6Label->setScaledContents(true);
    ui->shuziTong7Label->resize(48,55);
    ui->shuziTong7Label->move(1596,884);
    ui->shuziTong7Label->setScaledContents(true);

}

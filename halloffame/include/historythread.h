#ifndef HISTORYTHREAD_H
#define HISTORYTHREAD_H

#include <QThread>
#include <QtSql>

#include "widget.h"

class Widget ;

class HistoryThread : public QThread
{
    Q_OBJECT

public:
    explicit HistoryThread(Widget& mo_widget);
    ~HistoryThread();

    Widget& mo_widget;
    QSqlDatabase db ;
    bool isFirstTime;

    QPixmap picJin;
    QPixmap picYin;
    QPixmap picTong;

    QString scoreJin ;
    QString scoreYin ;
    QString scoreTong ;

    bool b_is_db_connected ;

    void run();
    void connect_db() ;

    void getZhouData() ;
    void getYueData() ;
    void getJiData() ;

    QString getZhouBegin();
    QString getZhouEnd();
    QString getYueBegin();
    QString getYueEnd();
    QString getJiBegin();
    QString getJiEnd();

    void stateToggle();
    void touxiangToggle();
    void shuziShow();

signals:
    void sigHideAll();
    void sigTouxiangShow(const int rank=0, const QPixmap& pic=QPixmap(""));
    void sigShuziShow(const int rank=0, const QString& score="");

};

#endif // HISTORYTHREAD_H

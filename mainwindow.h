#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <board.h>
#include "menu.h"
#include "ai.h"
#include<QWidget>
#include <QPushButton>
class QPaintEvent;
class menu;
QT_BEGIN_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool flag;//判断是否暂停状态
    QTimer *timer;//定时器
    Board *board;//游戏所用地图类
    int rank;
    int pictureID;
    int aiLead;

    MainWindow(Board *, int, int, int, QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);//绘制界面
    void keyPressEvent(QKeyEvent *);//键盘事件处理
    QPushButton *quitButton;
    QPushButton *stopButton;

signals:

public slots:
    void timerEvent();//定时事件
    void back();
    void stop();

private:
    menu *w;
};

#endif // MAINWINDOW_H


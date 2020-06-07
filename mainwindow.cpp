#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <QMessageBox>
#include "brick.h"
#include<QWidget>
#include<QGridLayout>
#include <QIcon>
#include <QtWidgets>
using namespace std;

MainWindow::MainWindow(Board *board, int rank, int pictureID, int aiLead, QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle("Superhero Tetris");
    this->board = board;
    flag = 1;
    this->rank = rank;
    this->pictureID = pictureID;
    this->aiLead = aiLead;
    //初始化定时器
    timer = new QTimer(this);
    timer->setInterval(this ->rank * 100);
    //为定时器设置连接函数
    connect(timer, &QTimer::timeout, this, &MainWindow::timerEvent);

    timer->start();
    resize(10*63.25, 20*44.55);

    quitButton = new QPushButton(this);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(back()));//返回按钮
    quitButton->setFocusPolicy(Qt::ClickFocus);//否则方向键操作无响应
    stopButton = new QPushButton(this);
    connect(stopButton,SIGNAL(clicked()),this,SLOT(stop()));//返回按钮
    stopButton->setFocusPolicy(Qt::NoFocus);//否则方向键操作无响应

}

void MainWindow::stop()
{
    timer->stop();
    flag = 1;
    QMessageBox::information(this, tr("提醒"), tr("回到游戏"));
    flag = 0;
    timer->start();

}

void MainWindow::back()
{
    w = new menu;
    w->show();
    timer->stop();
    this->close();

}

void MainWindow::paintEvent(QPaintEvent *)
{
    float w = (float)this->width()/14.375;
    float h = (float)this->height()/20.25;
    float w1 = (float)this->width()/115;
    float h1 = (float)this->height()/162;
    QPainter painter(this);
    painter.setBrush(Qt::black);
    switch (this->pictureID) {
    case 1:
        painter.drawPixmap(w1,h1, w*10, h*20,  QPixmap(":/new/prefix1/background1.jpg"));
        break;
    case 2:
        painter.drawPixmap(w1,h1, w*10, h*20,  QPixmap(":/new/prefix1/background2.jpg"));
        break;
    case 3:
        painter.drawPixmap(w1,h1, w*10, h*20,  QPixmap(":/new/prefix1/background3.jpg"));
        break;
    case 4:
        painter.drawPixmap(w1,h1, w*10, h*20,  QPixmap(":/new/prefix1/background4.jpg"));
        break;
    case 5:
        painter.drawPixmap(w1,h1, w*10, h*20,  QPixmap(":/new/prefix1/background5.jpg"));
        break;
    default:
        break;
    }
    painter.drawPixmap(w1*2+w*10,h1, w*4, h*4, QPixmap(":/new/prefix1/background6.png"));
    painter.drawPixmap(w1*2+w*10,h1*2+h*4, w*4,this->height()-h1*3-h*4 , QPixmap(":/new/prefix1/background6.png"));


    //绘制背景方法2
    for(int i=0; i<=20; i++)
    {
        for(int j=1; j<=10; j++)
        {
            char ch = board->map[i][j];
            if(ch != '#')
            {
                     if ( ch == '1')
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/1.jpg"));
                     else if ( ch == '2')
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/2.jpg"));
                     else if ( ch == '3')
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/3.jpg"));
                     else if ( ch == '4')
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/4.jpg"));
                     else if ( ch == '5')
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/5.jpg"));
                     else if ( ch == '6')
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/6.jpg"));
                     else if ( ch == '*')
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/ai.PNG"));
                     else
                         painter.drawPixmap(j*w-w+w1, i*h-h+h1, w, h, QPixmap(":/new/prefix1/7.jpg"));
            }
        }
    }
        painter.setBrush(Qt::darkGray);
        painter.drawRect(0, 0, this->width(), h1);//上面一行
        painter.drawRect(w1+10*w, h1+4*h, this->width(), h1);//左边中间一行
        painter.drawRect(0, h1+h*20, this->width(), h);//下面一行
        painter.drawRect(0, 0,w1, this->height());//左边一列
        painter.drawRect(w1+w*10, 0, w1, this->height());//中间一列
        painter.drawRect(w1*2+w*14, 0,w, this->height());//右边一列

    //绘制下一个块的提示
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            int ch = board->brick->block[board->brick->nextShape][i][j];
            if(ch != '#')
            {
                 if ( ch == '1')
                 painter.drawPixmap((j+10+0.5)*w+w1*2, (i+0.5)*h+h1*2, w, h , QPixmap(":/new/prefix1/1.jpg"));
                 else if ( ch == '2')
                 painter.drawPixmap((j+10+0.5)*w+w1*2, (i+0.5)*h+h1*2, w, h , QPixmap(":/new/prefix1/2.jpg"));
                 else if ( ch == '3')
                  painter.drawPixmap((j+10+0.5)*w+w1*2, (i+0.5)*h+h1*2, w, h , QPixmap(":/new/prefix1/3.jpg"));
                 else if ( ch == '4')
                  painter.drawPixmap((j+10+0.5)*w+w1*2, (i+0.5)*h+h1*2, w, h , QPixmap(":/new/prefix1/4.jpg"));
                 else if ( ch == '5')
                  painter.drawPixmap((j+10+0.5)*w+w1*2, (i+0.5)*h+h1*2,w, h , QPixmap(":/new/prefix1/5.jpg"));
                 else if ( ch == '6')
                  painter.drawPixmap((j+10)*w+w1*2, (i)*h+h1*1, w, h , QPixmap(":/new/prefix1/6.jpg"));
                 else
                  painter.drawPixmap((j+10+1)*w+w1*2, (i+1)*h+h1*2, w, h , QPixmap(":/new/prefix1/7.jpg"));
            }
        }

    //绘制当前正在下落的块
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            int tx = board->brick->x + i;
            int ty = board->brick->y + j;
            if(tx<1 || tx > 20 || ty < 1 || ty > 10)
                continue;
            int ch = board->brick->block[board->brick->shape][i][j];
            if(ch != '#')
            {

                    if ( ch == '1')
                    painter.drawPixmap(ty*w-w+w1, tx*h-h+h1, w, h, QPixmap(":/new/prefix1/1.jpg"));
                    else if ( ch == '2')
                    painter.drawPixmap(ty*w-w+w1, tx*h-h+h1, w, h, QPixmap(":/new/prefix1/2.jpg"));
                    else if ( ch == '3')
                     painter.drawPixmap(ty*w-w+w1, tx*h-h+h1,w, h, QPixmap(":/new/prefix1/3.jpg"));
                    else if ( ch == '4')
                    painter.drawPixmap(ty*w-w+w1, tx*h-h+h1, w, h, QPixmap(":/new/prefix1/4.jpg"));
                    else if ( ch == '5')
                     painter.drawPixmap(ty*w-w+w1, tx*h-h+h1, w, h, QPixmap(":/new/prefix1/5.jpg"));
                    else if ( ch == '6')
                     painter.drawPixmap(ty*w-w+w1, tx*h-h+h1, w, h, QPixmap(":/new/prefix1/6.jpg"));
                    else
                     painter.drawPixmap(ty*w-w+w1, tx*h-h+h1, w, h, QPixmap(":/new/prefix1/7.jpg"));
            }
        }

    //绘制分数信息
    QFont font;
    font.setPointSize(13);
    painter.setFont(font);
    painter.setPen(Qt::white);

    char s[10];
    char level[8][11]={"","地狱","困难","","普通","","","简单"};
    sprintf(s, "%s\n", level[this->rank]);
    painter.drawText(10*w+this->width()/575*60, 6*h, "难度");
    painter.drawText(10*w+this->width()/575*60, 7*h, s);
    sprintf(s, "%3d",board->scoreRank[0]);
    painter.drawText(10*w+this->width()/575*60, 8*h, "最高分");
    painter.drawText(10*w+this->width()/575*60, 9*h, s);
    painter.drawPixmap(w1*2+10*w,this->height()-h*6-h1, w*4, h*6,  QPixmap(":/new/prefix1/DC.jpg"));
    sprintf(s, "%3d", board->score);
    painter.drawText(10*w+this->width()/575*60, 10*h, "当前分");
    painter.drawText(10*w+this->width()/575*60, 11*h, s);

    quitButton->setStyleSheet(tr("border-image: url(:/new/prefix1/back2.jpg);"));
    quitButton->setGeometry(w1*2+10*w,this->height()-h*8-h1, w*4, h*2);
    quitButton->show();
    stopButton->setStyleSheet(tr("border-image: url(:/new/prefix1/DC.jpg);"));
    stopButton->setGeometry(w1*2+10*w,this->height()-h*6-h1, w*4, h*6);
    stopButton->show();
}


void MainWindow::timerEvent()
{
    //碰撞检测符合条件则下落
    if (flag== 1)
    {

        board->brick->toNext();
        board->score = 0;

        //初始化地图
        for(int i=0; i<=21; i++)
            for(int j=0; j<=11; j++)
                board->map[i][j] = '#';
        for(int i=0; i<=21; i++)
                board->map[i][0] = board->map[i][11] = '@';
            for(int i=1; i<=10; i++)
                board->map[21][i] = '@';

        flag = 0;

        if(aiLead && board->brick->AIflag)
        {
            board->brick->AIflag=false;
            int X,Y,type;
            AI ai(board->map,board->brick->shape);
            ai.AIgo(X,Y,type);
            for(int i = 0; i < 4; i++)
                 for(int j = 0; j < 4; j++)
                 {
                     if(board->brick->block[type][i][j] != '#')
                         board->map[X+i][Y+j] = '*';
                 }
        }
    }
    if(board->brick->collisionJudge(1)){

        if(aiLead && board->brick->AIflag)//刚进入的块进行判断
        {
            board->brick->AIflag=false;
            int X,Y,type;
            AI ai(board->map,board->brick->shape);
            ai.AIgo(X,Y,type);
            for(int i = 0; i < 4; i++)
                 for(int j = 0; j < 4; j++)
                 {
                     if(board->brick->block[type][i][j] != '#')
                         board->map[X+i][Y+j] = '*';
                 }
        }

        board->brick->moveDown();
    }
    else
    {
        //否则暂停并弹窗提示
        timer->stop();

        for (int i = 1; i <= 20; i++)
            for(int j = 1; j <= 10 ; j++)
                if (board->map[i][j] == '*')
                    board->map[i][j] = '#';

        board->addTomap();


        if(board->endJudge())
        {
            timer->stop();
            //重玩
            if (QMessageBox::Yes ==
                    QMessageBox::question(this, tr("提醒"), tr("游戏结束，再来一把吧?"),
                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
            {
                QMessageBox::information(this, tr("提醒"), tr("哈哈，准备好了吗"));

                board->brick->toNext();
                board->score = 0;

                //初始化地图
                for(int i=0; i<=21; i++)
                    for(int j=0; j<=11; j++)
                        board->map[i][j] = '#';
                for(int i=0; i<=21; i++)
                        board->map[i][0] = board->map[i][11] = '@';
                    for(int i=1; i<=10; i++)
                        board->map[21][i] = '@';

            }
            //退出
            else
            {
                QMessageBox::information(this, tr("Game Over"), tr("Game Over"));
                exit(1);
            }
        }
        timer->start();
    }
    //更新界面
    this->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //回车键暂停游戏
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        timer->stop();
        flag = 1;
        QMessageBox::information(this, tr("提醒"), tr("回到游戏"));
        flag = 0;
        timer->start();
    }

    //若处在暂停状态则忽略其他的按键
    if(flag)
        return;

    if(event->key() == Qt::Key_Up)
    {
        if(board->brick->collisionJudge(0))
            board->brick->changeShape();
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(board->brick->collisionJudge(1))
            board->brick->moveDown();
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(board->brick->collisionJudge(2))
            board->brick->moveLeft();
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(board->brick->collisionJudge(3))
            board->brick->moveRight();
    }
    else if(event->key() == Qt::Key_F5) //按F5刷新排行榜，隐藏功能
    {
        FILE *fd =fopen("score.bin","wb+");
            for(int i=0;i<10;i++)
            fprintf(fd, "%d\n", 0);
            fclose(fd);

    }
    //更新界面
    this->update();
}

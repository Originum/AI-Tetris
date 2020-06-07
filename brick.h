#ifndef BRICK_H
#define BRICK_H
#include "board.h"
#include <QPainter>
#include<QWidget>
class Board;

class Brick

{
public:
    char block[20][5][5];//各个类型的方块

    int next[20];//模拟指向用于方块旋转

    int x;//块重心起始坐标

    int y;

    int shape;//块id

    int nextShape;//下一个块id

    Board *board;

    Brick(Board *);//构造函数

    void toNext();//更改块id

    void changeShape();//变形

    void moveRight();//加速

    void moveLeft();//左移

    void moveDown();//右移

    bool collisionJudge(int);//碰撞检测

    int random();

    int AIflag;

};

#endif // BRICK_H

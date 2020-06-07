#ifndef AI_H
#define AI_H

#include <iostream>
using namespace std;

class AI
{
public:
    AI(char MAP[100][100], int);
       int LandingHeight;
       int RowsEliminated;
       int RowTransitions();
       int ColumnTransitions();
       int NumberofHoles();
       int WellSums();
       int PierreDellacherie();

       bool collisionJudge(int, int);
       void addTomap(int, int);
       void AIgo(int &X, int &Y,int &shape);


   private:
       int maxValue;
       char map[22][12];//用来操作
       char copyMap[22][12];//记录传入情况
       char cur[4][4];
       int type;//可以传出

};

#endif // AI_H

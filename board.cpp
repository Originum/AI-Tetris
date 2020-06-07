#include "board.h"

#include "brick.h"

#include <fstream>

#include <iostream>

using namespace std;

Board::Board()
{

    //初始化块，时间间隔，分数


    brick = new Brick(this);

    //从文件读入最高分

    FILE *fd =fopen("score.bin","rb+");
    for(int i=0;i<10;i++)
    fscanf(fd, "%d", scoreRank+i);

    //初始化地图

    for(int i=0; i<=21; i++)

        for(int j=0; j<=11; j++)

            map[i][j] = '#';
    for(int i=0; i<=21; i++)
            map[i][0] = map[i][11] = '@';
        for(int i=1; i<=10; i++)
            map[21][i] = '@';

}

void Board::addTomap()

{

    //将块更新到map

    for(int i=0; i<4; i++)

        for(int j=0; j<4; j++)

        {

            int tx = brick->x + i;

            int ty = brick->y + j;

            if(tx<1 || tx > 20 || ty < 1 || ty > 10)

                continue;

            if(brick->block[brick->shape][i][j] != '#')

                map[tx][ty] = brick->block[brick->shape][i][j];

        }

    //消去完整的行并计算行个数

    int cnt = 0;

    for(int i=20; i>=1; i--)

    {

        bool flag = false;

        for(int j=1; j<=10; j++)

            if(map[i][j] == '#')

            {

                flag = true;

                break;

            }

        if(flag)

            continue;

        cnt++;

        for(int j=i; j>=1; j--)

            for(int k=1; k<=10; k++)

                map[j][k] = map[j-1][k];

        i++;
    }

    if(cnt)
        score += 1<<(cnt-1);
    brick->toNext();

}

bool Board::endJudge()

{

    for(int i=1; i<=10; i++)

        if(map[1][i] != '#')

        {

            //如果游戏结束，计入排行榜

            for(int i=0;i<10;i++)
                   {
                       if(score > scoreRank[i])
                       {
                           for(int j=  9;j > i;j --)
                               scoreRank[j]=scoreRank[j-1];
                           scoreRank[i]= score;
                           break;
                       }
            }

            FILE *fd =fopen("score.bin","wb+");
            for(int i=0;i<10;i++)
            fprintf(fd, "%d\n", scoreRank[i]);

            fclose(fd);

            return true;

        }

    return false;

}

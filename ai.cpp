#include "ai.h"

AI :: AI(char MAP[100][100], int TYPE) {//获得当前局势
    type = TYPE;//传入方块的值
    for(int i = 0;i < 22; i++)
        for(int j = 0;j < 12; j++) {
            if (MAP[i][j] != '#')
            copyMap[i][j] = MAP[i][j];
            else copyMap[i][j]=0;//空格赋值为0
        }
    for (int i = 1 ; i <= 10 ; i ++ )
        copyMap[0][i] = '@';
    maxValue = -0x3f3f3f;
}


bool AI :: collisionJudge(int x ,int y) { //碰撞检测只需要检测向下移动时的状态（由于变形是被枚举，左右移动不是用户操作的，一开始一定水平先移动到最优位置）,用传入地图

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            int tx = x+i;
            int ty = y+j;
            if(cur[i][j] && (tx <= 0 || tx >= 21 || ty <= 0 || ty >= 11))
                return false;
            if(cur[i][j] && copyMap[tx][ty]) //有方块重合
                return false;
        }
    return true;
}

void AI :: addTomap(int x, int y) {


    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {

            int tx = x + i;
            int ty = y + j;

            if(tx<1 || tx > 20 || ty < 1 || ty > 10)//界外不用考虑，加速
                continue;
            if(cur[i][j])
                map[tx][ty] = cur[i][j];
        }
    int maxHeight  = 21 - x;
    bool flag = true;
    for(int i=0; i<4 && flag; i++)
        for(int j=0; j<4; j++) {
            if (cur[i][j])
            {maxHeight -= i;flag = false; break;}
        }
    int minHeight = 18 - x;
    flag = true;
    for(int i=3; i>=0 && flag; i--)
        for(int j=0; j<4; j++) {
            if (cur[i][j])
            {minHeight += (3-i);flag = false; break;}
        }
    LandingHeight = (maxHeight + minHeight)/2;
    int cnt =0, sum=0;
    for(int i=20; i>=1; i--)
    {
        bool flag = false;
        for(int j=1; j<=10; j++)
            if(!map[i][j])
            {
                flag = true;
                break;
            }
        if(flag)
            continue;
        cnt++;//行数

        for(int ii = 1; ii <= 10; ii ++)
            if (map[i][ii] == '#') sum ++;//计算被消去个数

        for(int j=i; j>1; j--)
            for(int k=1; k<=10; k++)
                map[j][k] = map[j-1][k];
        i++;
    }

    RowsEliminated = cnt * sum;
}

int AI :: RowTransitions() {
    int cnt = 0;
    for(int i = 1; i <= 20; i ++)
        for(int j = 0; j <= 10; j++) {
            if (!(map[i][j]&&map[i][j+1]) && (map[i][j]||map[i][j+1]))
                    cnt ++;
        }
    return cnt;
}

int AI :: ColumnTransitions() {
    int cnt = 0;
    for(int j = 1; j <= 10; j ++)
        for(int i = 0; i <= 20; i++) {
            if (!(map[i][j]&&map[i+1][j]) && (map[i][j]||map[i+1][j]))
                cnt ++;
        }
    return cnt;
}

int AI :: NumberofHoles() {
    int cnt = 0;
    bool flag;
    for(int j = 1; j <= 10; j ++){
        flag = false;
        for(int i = 1; i <= 20; i++) {
            if (map[i][j]) flag = true;
            else
                if (flag == true) {
                    cnt ++;
                    flag = false;
                }
        }
    }
    return cnt;
}

int AI :: WellSums() {
    int sum = 0,cnt = 0;
    int well[21] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105,
        120, 136, 153, 171, 190, 210};

    for(int j = 1; j <= 10; j ++)
        for(int i = 1; i <= 20; i++) {
            if(!map[i][j] && map[i][j-1] && map[i][j+1]) {
                cnt ++;
            }
            else {
                sum += well[cnt];
                cnt = 0;
            }
        }
    return sum;
}

void AI :: AIgo(int &X, int &Y,int &shape) {
    int Next[19]={1,0,3,2,5,6,7,4,9,10,11,8,13,14,15,12,17,16,18};
    int bag[7]={2,2,4,4,4,2,1};  //有几种变形
    int bagID[19]={0,0,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,6};//type对应
    char b[19][5][5]=
    {
        {
            "1###",
            "11##",
            "#1##",
            "####"
        },
        {
            "#11#",
            "11##",
            "####",
            "####"
        },
        {
            "#2##",
            "22##",
            "2###",
            "####"
        },
        {
            "22##",
            "#22#",
            "####",
            "####"
        },
        {
            "#3##",
            "#3##",
            "#33#",
            "####"
        },
        {
            "####",
            "333#",
            "3###",
            "####"
        },
        {
            "33##",
            "#3##",
            "#3##",
            "####"
        },
        {
            "##3#",
            "333#",
            "####",
            "####"
        },
        {
            "#4##",
            "#4##",
            "44##",
            "####"
        },
        {
            "4###",
            "444#",
            "####",
            "####"
        },
        {
            "#44#",
            "#4##",
            "#4##",
            "####"
        },
        {
            "####",
            "444#",
            "##4#",
            "####"
        },
        {
            "#5##",
            "555#",
            "####",
            "####"
        },
        {
            "#5##",
            "#55#",
            "#5##",
            "####"
        },
        {
            "####",
            "555#",
            "#5##",
            "####"
        },
        {
            "#5##",
            "55##",
            "#5##",
            "####"
        },
        {
            "#6##",
            "#6##",
            "#6##",
            "#6##"
        },
        {
            "####",
            "6666",
            "####",
            "####"
        },
        {
            "77##",
            "77##",
            "####",
            "####"
        }
    };

    for(int t = 0; t < bag[bagID[type]]; t++) { //不同变形枚举
        type = Next[type];
        for (int i = 0; i < 4;i ++)//得到枚举的方块
            for (int j = 0; j < 4;j ++) {
                if (b[type][i][j] == '#')
                    cur[i][j] = 0;
                else
                    cur[i][j] = '#';//特殊标记。此时形状无意义
            }

        for (int i = 0; i <= 10; i++) {
            if (collisionJudge(1,i)) { //当在第一行都判段为碰撞时，就是出界，不用考虑,理论上也不考虑方块逼近到最高处的可能性
                int j = 1;
                while (collisionJudge(++j,i));//当没触底碰撞时，向下移动
                j --;

                for(int ii = 0;ii < 22; ii++)//更新
                    for(int jj = 0;jj < 12; jj++)
                        map[ii][jj] = copyMap[ii][jj];

                //把块加入map

                addTomap(j, i);
                int value = PierreDellacherie();
                if (value > maxValue) {
                    X = j;
                    Y = i;
                    shape = type;
                    maxValue = value;
                }
            }
        }
    }
}

int AI :: PierreDellacherie() {


    int score =-45*LandingHeight + 34*RowsEliminated -
    32*RowTransitions() -
    93*ColumnTransitions() -
    79*NumberofHoles() -
    34*WellSums();

    return score;
}

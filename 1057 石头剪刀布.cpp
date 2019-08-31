#include <iostream>
#include <memory.h>
using namespace std;

//多加一圈栅栏
#define MAX_N 103

//这题有歧义，就是战斗顺序
//但如果只判断自己上下位置是否有死敌，如果有死敌就被他吃掉
//这样貌似就没有任何歧义
int main( void )
{
    int r, c, n, i, j, k;

    //mat是初始地图，mat2是当天搏杀后的结果地图
    //每天结束后要把mat2拷贝回mat地图，比较时使用mat地图
    char mat[MAX_N][MAX_N], mat2[MAX_N][MAX_N];

    //用数组表示上，右，下，左四个邻居
    int xoffset[4]={0,1,0, -1};
    int yoffset[4]={-1,0,1, 0};

    //读入行数、列数、天数
    cin>>r>>c>>n;
    //读入地图，地图四周要加围栏(避免边界判断的麻烦），所以下标从1开始
    for(i=1; i<=r; ++i)
    {
        for(j=1; j<=c; ++j)
            cin>>mat[i][j];
    }

    //最下和最上加一层栅栏(避免边界判断的麻烦），用'F'表示栅栏
    for(i=0; i<=c+1; ++i)
    {
        mat[0][i] = 'F';
        mat[r+1][i] = 'F';
    }
    //最左和最右加一层栅栏(避免边界判断的麻烦），用'F'表示栅栏
    for(i=0; i<=r+1; ++i)
    {
        mat[i][0] = 'F';
        mat[i][c+1] = 'F';
    }

    //计算n天后结果
    while(n-->0)
    {
        for(i=1; i<=r; ++i)
        {
            for(j=1; j<=c; ++j)
            {
                //先把当前位置初始化
                mat2[i][j] = mat[i][j];
                //之判断自己上下位置是否有死敌，如果有死敌就被他吃掉
                //这样貌似就没有任何歧义
                //每次结果要刷新在mat2中，而比较是用mat进行比较
                for(k=0; k<4; ++k)
                {
                    //自己是石头，邻居是布,被吃
                    if(mat[i][j]=='R'&&mat[i+xoffset[k]][j+yoffset[k]]=='P')
                    {
						//这里不能使用mat，搏杀结果是存储在mat2中的
                        mat2[i][j]='P';
                        //被吃后就退出本次比较
                        break;
                    }
                    //自己是剪刀，邻居是石头,被吃
                    else if(mat[i][j]=='S' && mat[i+xoffset[k]][j+yoffset[k]]=='R')
                    {
						//这里不能使用mat，搏杀结果是存储在mat2中的
                        mat2[i][j]='R';
                        //被吃后就退出本次比较
                        break;
                    }
                    //自己是布，邻居是剪刀,被吃
                    else if(mat[i][j]=='P'&&mat[i+xoffset[k]][j+yoffset[k]]=='S')
                    {
						//这里不能使用mat，搏杀结果是存储在mat2中的
                        mat2[i][j]='S';
                        //被吃后就退出本次比较
                        break;
                    }
                }
            }
        }
        //将当天搏杀后的结果拷贝回mat地图
        memcpy(mat, mat2, sizeof(mat));
    }

    for(i=1; i<=r; ++i)
    {
        for(j=1; j<=c; ++j)
        {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    return 0;
}


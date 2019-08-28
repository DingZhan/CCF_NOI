#include <iostream>

using namespace std;

#define MAX_N 101

//二维数组，用来存储方阵结果
int mat[MAX_N][MAX_N];

//下一个数字的移动方向
enum MoveDir{DOWN, RIGHTUP, RIGHT, LEFTDOWN};

int main()
{
    int i,j, n, num, id;
    //初始方向向下
    MoveDir dir=DOWN;
    //读入方阵长度
    cin>>n;
    //最大数字
    num = n*n;

    //初始行坐标和列坐标为(0,0)
    i = j = 0;
    //矩阵(0,0)元素为1
    mat[i][j] = 1;
    //从2到num摆放数字
    for(id=2; id<=num; ++id)
    {
        //方向向下
        if(dir==DOWN)
        {
            //行号加1
            ++i;
            //设置当前数字
            mat[i][j] = id;
            //如果已经在最左边，则下一个移动方向：右上
            if(j==0)
                dir = RIGHTUP;
            else //如果已经在最右边，则下一个移动方向：左下
                dir = LEFTDOWN;
        }
        else if(dir==RIGHTUP) //方向右上
        {
            //行号减1
            --i;
            //列号加1
            ++j;
            //设置当前数字
            mat[i][j] = id;
            //如果已经在最右边，则下一个移动方向：下
            if(j==n-1)
                dir = DOWN;
            else if(i==0) //如果已经在最上边，则下一个移动方向：右
                dir = RIGHT;
        }
        else if(dir==RIGHT) //方向右
        {
            //列号加1
            ++j;
            //设置当前数字
            mat[i][j] = id;
            //如果已经在最上边，则下一个移动方向：左下
            if(i==0)
                dir = LEFTDOWN;
            else //如果已经在最下边，则下一个移动方向：右上
                dir = RIGHTUP;
        }
        else if(dir==LEFTDOWN) //方向左下
        {
            //行号加1
            ++i;
            //列号减1
            --j;
            //设置当前数字
            mat[i][j] = id;
            if(i==n-1) //如果已经在最下边，则下一个移动方向：右
                dir = RIGHT;
            else if(j==0) //如果已经在最左边，则下一个移动方向：下
                dir = DOWN;
        }
    }
    //打印结果
    for(i=0; i<n; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(j!=0)
                cout<<" ";
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

//螺旋矩阵问题

//如果一个瓷砖已经被访问过，则将该瓷砖的数字改成INVALID，表示已经访问过了
#define INVALID -10000000

int main()
{
    //不禁止I/O同步就得0分
    std::ios::sync_with_stdio(false);

    int n, m, i, j, count, total=0;
    //因为不确定m和n的最大长度，所以干脆用vector<vector<int>>存地板瓷砖编号
    vector<vector<int> > grids;

    //读入矩形长和宽
    cin>>n>>m;
    //分配行数据
    grids.resize(n);
    for(i=0; i<n; ++i)
    {
        //分配第i行m列数据
        grids[i].resize(m);
        //读入每行瓷砖上的编号
        for(j=0; j<m; ++j)
            cin>>grids[i][j];
    }

    //初始化行号和列号
    i=0;
    //这里初始化列号为-1，因为我们要先向右走一步进入计算矩阵
    j=-1;
    //统计每行已打印的数字个数，当count==m时候我们就需要打印一个回车并且把count清为0
    count = 0;
    //一共需要打印的总数据量
    total = m*n;

    //开始循环，共需要打印total个瓷砖
    while(total!=0)
    {
        //先向右走一个，到达起始位置，这也是j初始化为-1的原因
        ++j;
        //一直向右走，直到碰到墙或者右边的瓷砖已经访问过
        while(j<m && grids[i][j]!=INVALID)
        {
            //注意是否需要先打印个空格
            if(count!=0)
                cout<<" ";
            //打印数字
            cout<<grids[i][j];
            //将瓷砖标识为已访问
            grids[i][j] = INVALID;
            //继续向右
            ++j;
            //累加已打印瓷砖数
            ++count;
            //如果已经达到m，则打印个回车，并且把count清0
            if(count==m)
            {
                cout<<endl;
                count = 0;
            }
            //目标数减一
            --total;
        }
        //往后回退一格
        --j;

        //先向下走一格
        ++i;
        //一直向下走，直到碰到墙或者下边的瓷砖已经访问过
        while(i<n && grids[i][j]!=INVALID)
        {
            //注意是否需要先打印个空格
            if(count!=0)
                cout<<" ";
            //打印数字
            cout<<grids[i][j];
            //将瓷砖标识为已访问
            grids[i][j] = INVALID;
            //继续向下
            ++i;
            //累加已打印瓷砖数
            ++count;
            //如果已经达到m，则打印个回车，并且把count清0
            if(count==m)
            {
                cout<<endl;
                count = 0;
            }
            //目标数减一
            --total;
        }
        //往后回退一格
        --i;

        //先向左走一格
        --j;
        while(j>=0 && grids[i][j]!=INVALID)
        {
            //注意是否需要先打印个空格
            if(count!=0)
                cout<<" ";
            //打印数字
            cout<<grids[i][j];
            //将瓷砖标识为已访问
            grids[i][j] = INVALID;
            //继续向左
            --j;
            //累加已打印瓷砖数
            ++count;
            //如果已经达到m，则打印个回车，并且把count清0
            if(count==m)
            {
                cout<<endl;
                count = 0;
            }
            //目标数减一
            --total;
        }
        //往后回退一格
        ++j;

        //先向上走一格
        --i;
        while(i>=0 && grids[i][j]!=INVALID)
        {
            //注意是否需要先打印个空格
            if(count!=0)
                cout<<" ";
            //打印数字
            cout<<grids[i][j];
            //将瓷砖标识为已访问
            grids[i][j] = INVALID;
            //继续向上
            --i;
            //累加已打印瓷砖数
            ++count;
            //如果已经达到m，则打印个回车，并且把count清0
            if(count==m)
            {
                cout<<endl;
                count = 0;
            }
            //目标数减一
            --total;
        }
        //往后回退一格
        ++i;
    }


    return 0;
}


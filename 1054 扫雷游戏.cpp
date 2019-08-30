#include <iostream>
#include <iomanip>

using namespace std;

//地图最大范围,因为加了两层栅栏，所以最大长度需要扩充到102
#define MAX_MN 102

int main( void )
{
    //地图
    char graph[MAX_MN][MAX_MN];
    int n, m, i, j, k, count;

    //用两个偏移位置数组，组织左上，上，右上，右，右下，下，左下，左共八个位置
    int xoffset[8]={-1, 0, 1, 1, 1, 0, -1, -1};
    int yoffset[8]={-1, -1, -1, 0, 1, 1, 1, 0};

    //读入n行和m列数
    cin>>n>>m;
    //为了简化边界判断条件，把地图四周都加上一圈栅栏，标记为非地雷
    //所以，行和列下标索引都是从1开始
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            cin>>graph[i][j];
        }
    }
    //把地图上下两行加上一排栅栏，标记为非地雷
    for(i=0; i<=m+1; ++i)
    {
        graph[0][i] = '?';
        graph[n+1][i] ='?';
    }
    //把地图左右两列加上一排栅栏，标记为非地雷
    for(i=0; i<=n+1; ++i)
    {
        graph[i][0] = '?';
        graph[i][m+1] = '?';
    }

    //计算每个位置的四周地雷数目
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            //如果自己就是地雷，则输出地雷符号
            if(graph[i][j]=='*')
                cout<<"*";
            else//否则计算四周地雷数目
            {
                count = 0;
                //用八个偏移量检测8个位置
                for(k=0; k<8; ++k)
                {
                    if(graph[i+xoffset[k]][j+yoffset[k]]=='*')
                        ++count;
                }
                cout<<count;
            }
        }
        cout<<endl;
    }

    return 0;
}


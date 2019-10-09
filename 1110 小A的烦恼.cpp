#include <iostream>
#include <vector>

using namespace std;

//简单图问题
//这题不好直接用邻接矩阵表示，因为N太大，所以不好用二维数组表示,而且二维数组表示顺序有困难
//只能用邻接表表示，这里使用vector<vector<int> >表示邻接表
int main()
{
    int i, j, N, M, a, b;
    vector<vector<int> > mat;
    //必须加上取消I/O同步，否则超时
    std::ios::sync_with_stdio(false);


    //读入城市数和道路数
    cin>>N>>M;

    //构建一张N行的邻接表，序号从1开始，所以多分配一行
    mat.resize(N+1);

    //读入道路信息
    for(i=0; i<M; ++i)
    {
        //读入一条道路的两个城市
        cin>>a>>b;
        //把城市b添加到城市a的邻接表中
        mat[a].push_back(b);
        //把城市a添加到城市b的邻接表中
        mat[b].push_back(a);
    }

    //打印邻接表
    for(i=1; i<=N; ++i)
    {
        //打印第i座城市的直接相邻的城市
        for(j=0; j<mat[i].size(); ++j)
        {
            //注意空格要前置打印
            if(j!=0)
                cout<<" ";
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    return 0;
}

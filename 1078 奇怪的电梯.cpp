#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 202

//以下算法只使用了贪心，会有超时问题，因为一旦无解，可能就有可能死循环
bool A2B(int A, int B, int N, int steps[], int &count)
{
    bool bSucc=false;
    count = 0;
    while(A!=B)
    {
        if(A<B)
        {
            if(A+steps[A]<=N)
                A+=steps[A];
            else
            {
                A-=steps[A];
                if(A<0)
                    break;
            }
        }
        else if(A>B)
        {
            if(A-steps[A]>=1)
                A-=steps[A];
            else
            {
                if(A+steps[A]>N)
                    break;
                A+=steps[A];
            }
        }
        ++count;
    }
    if(A==B)
        bSucc = true;
    return bSucc;
}

//贪心+回溯
bool A2B2(int A, int B, int N, int steps[], int &count)
{
    if(A==B)
        return true;
    else if(A<=0||A>N)
        return false;

    ++count;
    if(A2B2(A+steps[A], B, N, steps, count))
        return true;
    --count;

    ++count;
    if(A2B2(A-steps[A], B, N, steps, count))
        return true;
    --count;
    return false;
}

//应该是图的宽度优先搜索问题BFS,原点是A，目标点是B,应该是先构建图graph[MAX_N][MAX_N]
//题目要求最短距离实际上就是从A到B的最短路径
//用Floyd算法吧,但只得了60分,这个错误主要是这张图是有向图不是无向图
int dis[MAX_N][MAX_N];
#define INFINITE 10000000
int Floyd(int A, int B, int N, int steps[])
{
    if(A==B)
        return 0;
    int i,j, k;
    //构建结点间(数字间）的连通图
    for(i=1; i<=N; ++i)
    {
        for(j=1; j<=N; ++j)
            dis[i][j] = INFINITE;
    }
    for(i=1; i<=N; ++i)
    {
        if(i+steps[i]>=1 && i+steps[i]<=N)
        {
            dis[i][i+steps[i]] = 1;
            //这句话才是我最大的问题，因为这个图不是无向图
            //dis[i+steps[i]][i] = 1;
        }
        if(i-steps[i]>=1 && i-steps[i]<=N)
        {
            dis[i][i-steps[i]] = 1;
            //这句话才是我最大的问题，因为这个图不是无向图
//            dis[i-steps[i]][i] = 1;
        }
    }
    for(k=1; k<=N; ++k)
    {
        for(i=1; i<=N; ++i)
        {
            if(i==k)
                continue;
            if(dis[i][k]==INFINITE)
                continue;
            for(j=1; j<=N; ++j)
            {
                if(j==k || j==i)
                    continue;
                if(dis[k][j]==INFINITE)
                    continue;
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j] = dis[i][k]+dis[k][j];
                    //dis[j][i] = dis[i][j];
                }
            }
        }
    }
    return dis[A][B];
}

//还是用图的宽度优先搜索BFS试试，一次通过
int BFS(int A, int B, int N, int steps[])
{
    if(A==B)
        return 0;
    //节点[1,N]的访问标记位，如果一个节点已经被访问过了，则不要再添加到搜索队列里去
    bool bTakens[MAX_N] = {false};
    //搜索队列，这里用pair表示，队列元素的种子是楼层ID+访问深度
    queue<pair<int, int> > seeds;
    //种子节点是楼层id+访问深度
    pair<int, int> seed; //value--depth
    int next, id, depth;
    //是否找到了到达B的路径
    bool bSucc=false;

    //特殊情况，一开始A和B就相等，不需要按电梯，所以返回0
    if(A==B)
        return 0;

    //设置起点访问标记
    bTakens[A] = true;
    //设置起点种子
    seed.first = A;
    seed.second = 0; //初始搜索深度为0
    //把起点A加到搜索队列
    seeds.push(seed);

    //当种子队列非空
    while(!seeds.empty())
    {
        //从队列前段弹出一个种子
        seed = seeds.front();
        seeds.pop();
        //当前种子的楼层id和访问深度
        id = seed.first;
        depth = seed.second;

        //向上按电梯后的楼层
        next = id+steps[id];
        //如果能到达B，则找到了方案
        if(next==B)
        {
            bSucc=true;
            //累加一次电梯运行
            ++depth;
            break;
        }
        //如果上行楼层有效并且未被访问过，则宽度遍历它
        if(next>=1 && next<=N && bTakens[next]==false)
        {
            //设置访问标记
            bTakens[next]=true;
            //设置种子楼层号
            seed.first = next;
            //设置访问深度
            seed.second = depth+1;
            //添加到种子队列
            seeds.push(seed);
        }

        //向下按电梯后的楼层
        next = id-steps[id];
        //如果能到达B，则找到了方案
        if(next==B)
        {
            bSucc=true;
            //累加一次电梯运行
            ++depth;
            break;
        }
        //如果下行楼层有效并且未被访问过，则宽度遍历它
        if(next>=1 && next<=N && bTakens[next]==false)
        {
            //设置访问标记
            bTakens[next]=true;
            //设置种子楼层号
            seed.first = next;
            //设置访问深度
            seed.second = depth+1;
            //添加到种子队列
            seeds.push(seed);
        }
    }
    //如果成功到达B，则输出访问深度
    if(bSucc)
        return depth;
    else//否则返回一个无穷大值
        return INFINITE;
}


int main ()
{
    int N, A, B, i;
    int steps[MAX_N], count=0;

    cin>>N>>A>>B;
    for(i=1; i<=N; ++i)
        cin>>steps[i];

        /*
    if(A2B2(A, B, N, steps, count))
        cout<<count<<endl;
    else
        cout<<"-1"<<endl;
        */
    count = Floyd(A, B, N, steps);
//    count = BFS(A, B, N, steps);
    if(count!=INFINITE)
        cout<<count<<endl;
    else
        cout<<"-1"<<endl;
}



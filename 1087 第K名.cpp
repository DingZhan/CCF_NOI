#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//定义选手的结构体
struct Player
{
    string name; //名字
    int time;   //时间
};

//定义比较函数
bool Compare(const Player& a, const Player& b)
{
    return a.time<b.time;
}

//最多选手数
#define MAX_N 101
int main ()
{
    int N, K, i;
    //选手数组
    Player players[MAX_N];
    //读入选手数目和需要查询的第K名
    cin>>N>>K;
    //读入N个选手名字和成绩
    for(i=0; i<N; ++i)
    {
        cin>>players[i].name>>players[i].time;
    }
    //根据成绩快速排序
    sort(players, players+N, Compare);
    //打印第K名姓名
    cout<<players[K-1].name<<endl;

    return 0;
}

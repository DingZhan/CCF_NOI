#include <iostream>
#include <algorithm>

using namespace std;

struct Volunteer
{
    short id;    //报名号
    int score; //笔试成绩
};
//按成绩降序排列，成绩相同时报名号小的排前面
bool SortByScoreDescent(const Volunteer& a, const Volunteer& b)
{
    if(a.score>b.score)
        return true;
    else if(a.score<b.score)
        return false;
    else
        return a.id<b.id;
}
//最多人数
#define MAX_N 5001
int main()
{
    int n, m, i, t;
    //志愿者数组
    Volunteer vs[MAX_N];
    //总人数和拟录取人数
    cin>>n>>m;
    //读入n个志愿者编号和笔试成绩
    for(i=0; i<n; ++i)
        cin>>vs[i].id>>vs[i].score;
    //按笔试成绩降序排列，成绩相同时，编号小的排在前面
    sort(vs, vs+n, SortByScoreDescent);
    //在面试分数线的当前人数，记住这里要减1
    t = (int)(m*1.5)-1;
    //延伸t，因为后续的t+1, t+2,...的人的成绩可能和t是一样的
    for(i=t+1; i<n; ++i)
    {
        if(vs[i].score!=vs[t].score)
            break;
    }
    //面试分数线的所有人数-1
    t = i-1;
    //输出分数线和人数
    cout<<vs[t].score<<" "<<t+1<<endl;
    //输出排序后的数组
    for(i=0; i<=t; ++i)
        cout<<vs[i].id<<" "<<vs[i].score<<endl;
    return 0;
}

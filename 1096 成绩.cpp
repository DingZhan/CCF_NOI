#include <iostream>
#include <vector>

using namespace std;

//把5门成绩封装在一个结构体中
struct Score
{
    int a, b, c, d, e;
};

int main()
{
    int n, m, i, id, result;
    //用vector容器做动态数组
    vector<Score> scores;
    Score s;

    cin>>n>>m;
    for(i=0; i<n; ++i)
    {
        cin>>s.a>>s.b>>s.c>>s.d>>s.e;
        scores.push_back(s);
    }
    //计算m个Mark成绩
    for(i=0; i<m; ++i)
    {
        //借用s结构体存储k系数
        cin>>s.a>>s.b>>s.c>>s.d>>s.e>>id;
        result = scores[id-1].a*s.a+scores[id-1].b*s.b+scores[id-1].c*s.c+
            scores[id-1].d*s.d+scores[id-1].e*s.e;
        if(i!=0)
            cout<<" ";
        cout<<result;
    }
}

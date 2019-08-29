#include <iostream>
#include <algorithm> //sort
#include <functional> //greater
#include <iomanip> //setprecision, fixed

using namespace std;

#define MAX_N 40

int main( void )
{
    //男孩身高数组，女孩身高数组
    float boys[MAX_N], girls[MAX_N], height;
    //bn=boys number, gn=girls number,
    int i, n, bn=0, gn=0;
    //性别字符串
    string gender;
    //读入n个学生
    cin>>n;
    for(i=0; i<n; ++i)
    {
        //读入性别和身高
        cin>>gender>>height;
        //如果性别为男性，则加入男孩数组，否则加入女孩数组
        if(gender=="male")
            boys[bn++] = height;
        else
            girls[gn++] = height;
    }
    //男孩数组升序排列
    sort(boys, boys+bn);
    //女孩数组降序排列
    sort(girls, girls+gn, std::greater<float>() );
    //打印男孩身高
    for(i=0; i<bn; ++i)
    {
        //注意空格在前面输出
        if(i!=0)
            cout<<" ";
        cout<<fixed<<setprecision(2)<<boys[i];
    }
    //打印女孩身高
    for(i=0; i<gn; ++i)
    {
        //男孩至少有一个，所以不用担心空格问题
        cout<<" "<<fixed<<setprecision(2)<<girls[i];
    }
    cout<<endl;

    return 0;
}


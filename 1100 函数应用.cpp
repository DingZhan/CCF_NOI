#include <iostream>
#include <cmath>

using namespace std;


long long F1(long long a)
{
    return a*11+24;
}
long long F2(long long a)
{
    return (a>>3)+3;
}
long long F3(long long a)
{
    return a*a+10*a+31;
}
long long F4(long long a)
{
    return a/13+31;
}
long long F5(long long a)
{
    return a-sqrt(a);
}
long long F6(long long a)
{
    return sqrt(a);
}
long long F7(long long a)
{
    return a%206211;
}
long long F8(long long a)
{
    return a|10311999;
}
long long F9(long long a)
{
    return a&19991124;
}
long long F10(long long a)
{
    return a^11241031;
}
typedef long long (*Callback)(long long a);

int main()
{
    Callback funcs[10];
    int m, i, j, x,y;
    long long a;

    funcs[0]=F1;
    funcs[1]=F2;
    funcs[2]=F3;
    funcs[3]=F4;
    funcs[4]=F5;
    funcs[5]=F6;
    funcs[6]=F7;
    funcs[7]=F8;
    funcs[8]=F9;
    funcs[9]=F10;
    cin>>m;
    for(i=0; i<m; ++i)
    {
        cin>>x>>y>>a;
        x-=1;
        y-=1;
        swap(funcs[x], funcs[y]);
        for(j=0; j<10; ++j)
            a = funcs[j](a);
//        swap(funcs[x], funcs[y]);
        cout<<a<<endl;
    }

    return 0;
}

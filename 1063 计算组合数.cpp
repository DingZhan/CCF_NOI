#include <iostream>
#include <iomanip> //fixed setprecision
#include <cmath> //fabs

using namespace std;

//从编号1到n的球里面取m个球，一共有多少种取法
//这就是组合问题: C(n, m)
//题中n = 5, m = 2,即从5个球里面取2两个球的取法
//10组合情况如下:
/*
(1, 2),(1, 3),(1, 4),(1, 5),
(2, 3),(2, 4),(2, 5),
(3, 4),(3, 5),
(4, 5),
*/
//           n*(n-1)*(n-2)...*(n-m+1)
//C(n, m) =  ------------------------
//           1*2*3...........*m
//计算组合时注意溢出问题
int main( void )
{
    int n, m, i;
    unsigned long long t=1, b=1;
    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        t*=(n-i+1);
        b*=i;
    }
    cout<<t/b<<endl;
    return 0;
}


#include <iostream>

using namespace std;

//要算最小公倍数，先计算最大公约数
//这里利用辗转相除法计算最大公约数
//要理解辗转相除法，可以用10 35做例子

//最大公约数简写成gcd
int gcd(int a, int b)
{
    int c;
    c = a%b;
    while(c)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

//最小公倍数简写成lcm
int lcm(int a, int b)
{
    //先计算最大公约数
    int c = gcd(a, b);
    return (a/c)*(b/c)*c;
    //或者更简便的写成
//  return (a/c)*b;
}
int main( void )
{
    int n, m, t;
    cin>>n>>m;
    t = lcm(n, m);
    cout<<t<<endl;
    return 0;
}


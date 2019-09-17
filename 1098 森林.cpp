#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int c = a%b;
    while(c)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

/*
1
3-5/4=
*/

int main()
{
    int n, i, a, b, c;
    char op;
    //读入表达式总数n
    cin>>n;
    //读入n个表达式
    for(i=0; i<n; ++i)
    {
        //初始分子为0
        a = 0;
        //初始分母为1
        b = 1;
        //读入第一个数值
        cin>>a;
        //循环度直到读到'='号
        while(true)
        {
            //读入一个操作符
            cin>>op;
            //=号结束
            if(op=='=')
                break;
            //读入另一个操作数
            cin>>c;
            //分式表达式+
            if(op=='+')
            {
                a=a+b*c;
            }
            //分式表达式-
            else if(op=='-')
            {
                a=a-b*c;
            }
            //分式表达式*
            else if(op=='*')
            {
                a*=c;
            }
            //分式表达式/
            else if(op=='/')
            {
                b*=c;
            }
            //利用gcd得到最大公约数
            c = gcd(a, b);
            //这句话很重要，否则0分，因为gcd可能会得到负的公约数，这里必须确保分母为正
            if(c<0)
                c = -c;
            //对分子分母处以最大公约数
            a/=c;
            b/=c;
        }
        if(a==0)
            cout<<0<<endl;
//        else if(b==1)
//            cout<<a<<endl;
        else
            cout<<a<<"/"<<b<<endl;
    }
    return 0;
}

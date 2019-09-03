#include <iostream>

using namespace std;

//n是还剩多少级台阶
int Climb(int n)
{
    //还剩1级台阶时候只有1种走法
    if(n==1)
        return 1;
    else if(n==2) //还剩两级台阶时候有两种走法
        return 2;
    //剩n级台阶可走的方法是：走一步之后剩下n-1级台阶的方法 + 走两步后剩下n-2级台阶的方法
    return Climb(n-1)+ Climb(n-2);
}

int main( void )
{
    int steps, n;
    //读入台阶数
    while(cin>>steps)
    {
        //计算走的方法
        n = Climb(steps);
        cout<<n<<endl;
    }
    return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 10001

//本题思想就是把1-n的所有素数（质数）存储到一个数组中

//判断素数的函数
bool prime(int n)
{
    if(n<=1)
        return false;
    else if(n==2) //2是唯一的偶数素数
        return true;
    if(n%2==0) //如果是其它偶数，则一定不是素数
        return false;
    //n的循环因子上限sqrt(n)
    int i, t = sqrt(n);
    for(i=3; i<=t; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main( void )
{
    //1-n的所有素数（质数）存储到primes数组中
    int i, primes[MAX_N], p=0, n;
    cin>>n;
    primes[0] = 2;
    for(i=3, p=1; i<=n; i+=2)
    {
        //如果i是质数，则存储到数组中去
        if(prime(i))
            primes[p++] = i;
    }
    for(i=0; i<p-1; ++i)
    {
        if(primes[i+1]-primes[i]==2)
            cout<<primes[i]<<" "<<primes[i+1]<<endl;
    }
    return 0;
}


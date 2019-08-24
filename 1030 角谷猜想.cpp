#include <iostream>
#include <string>

using namespace std;

//卡拉兹猜想

int main()
{
    /*如果n不使用long long类型,则会有超时问题发生，应该是3*n+1时候溢出成负数了，所以这里使用long long类型避免溢出*/
    long long i=1, n;
    cin>>n;
    while(n!=1)
    {
        if(n%2==0)
            n/=2;
        else
            n = 3*n+1;
        ++i;
    }
    cout<<i<<endl;
    return 0;
}

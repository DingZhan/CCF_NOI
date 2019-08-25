#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    //整数每左移一位就相当于乘以2，所以1只要左移n位就能得到结果
    cout<<(1<<n)<<endl;
    return 0;
}

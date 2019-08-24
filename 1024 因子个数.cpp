#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i, num=0, t;
    cin>>n;
    //这样写循环会有超时问题
    /*
    for(i=1; i<=n; ++i)
    {
        if(n%i==0)
            ++num;
    }
    */
    //特殊处理n=1
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    //优化循环上限为t = sqrt(n);
    t = (int)sqrt(n);
    for(i=1; i<=t; ++i)
    {
        if(n%i==0)
        {
            //这里加2,是因为如果a是n的因子，必然会有一个b也是n的因子，其中a*b = n
            //其中a<=t, b>=t
            num+=2;
        }
    }
    //最后确认t*t是否等于n，如果是则num减1,因为t被重复累加了1次
    if(t*t==n)
        num-=1;
    cout<<num;
    return 0;
}

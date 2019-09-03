#include <iostream>

using namespace std;

int main( void )
{
    int n, i, j, k, a0, a1, a2;
    const int m=32767;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>k;
        //不要忘记每次都要初始化
        a0=1;
        a1=2;
        //特殊处理k=1, 2情形
        if(k==1)
            cout<<a0<<endl;
        else if(k==2)
            cout<<a1<<endl;
        else
        {
            for(j=2; j<k; ++j)
            {
                //迭代公式
                a2 = (2*a1+a0)%m;
                //刷新a0和a1
                a0 = a1;
                a1 = a2;
            }
            cout<<a2<<endl;
        }
    }
    return 0;
}


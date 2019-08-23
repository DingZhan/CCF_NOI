#include <iostream>

using namespace std;

int main()
{
    double x;
    int m;
    cin>>x;
    if(x<=0.5)
        m = 3;
    else
    {
        //前三分钟
        m = 3;
        x-=0.5;
        //由于浮点精度误差，这里补偿一个1.0e-6, 测试用例输入 x = 0.7
        x+=1.0e-6;
        //后面的时间
        m += (int)(x/0.2);
    }
    cout<<m<<endl;
    return 0;
}

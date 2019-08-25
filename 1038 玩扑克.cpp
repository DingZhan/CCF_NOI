#include <iostream>

using namespace std;

int main()
{
    //用一个计数器数组，计算每张牌出现的次数
    int counts[14]={0}, i, a;
    for(i=0; i<25; ++i)
    {
        cin>>a;
        ++counts[a];
    }
    //牌从1开始,计数器数组中第一个元素不使用
    for(i=1; i<=13; ++i)
    {
		//找到了只出现了一次的牌，即丢失的牌
        if(counts[i]==1)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

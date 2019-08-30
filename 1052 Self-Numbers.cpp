#include <iostream>

using namespace std;

//最多K次查询
#define MAX_K 5001
//N的最大值10^7
#define MAX_N 10000000
//估算1-MAX_N间最多有10^6个self数
#define MAX_S 1000000

//初始所有数字都是self数
bool nonself[MAX_N];

//把[1,N]之间所有self数字都存储到selfs数组中
int selfs[MAX_S];

int main( void )
{
    //ids是查询编号，即里面是第几个self数
    int i, j, N, K, ids[MAX_K], s;
    //读入最大N和K次查询
    cin>>N>>K;
    //读入K个查询self数的编号
    for(i=0; i<K; ++i)
        cin>>ids[i];

    //外层循环：遍历[1,N]作为初始发生器
    for(j=1; j<=N; ++j)
    {
        //如果当前j已经被作为发生器计算过了，则不要重复计算，否则会超时
        if(nonself[j])
            continue;
        //初始发生器值i
        i = j;
        //发生器的值不大于N
        while(i<=N)
        {
            //先累加i到s上
            s = i;
            //得到i的每位数字，并且累加到s上
            while(i)
            {
                s+=i%10;
                i/=10;
            }
            //更新发生器
            i = s;
            //如果之前已经发现i是非self数（有发生器的），则退出while循环
            //没有这个判断会有大量重复计算，导致超时
            if(nonself[i])
                break;
            //设置i是非self数，即当前i由其它发生器生成
            nonself[i] = true;
        }
    }

    //遍历nonself数组，把所有没有发生器的数字存储到selfs数组中
    for(i=1, j=0; i<=N; ++i)
    {
        if(nonself[i]==false)
        {
            selfs[j++] = i;
        }
    }
    //输出当前区间[1, N]中所有self数的个数
    cout<<j<<endl;
    //打印self数字查询结果
    for(i=0; i<K; ++i)
    {
        if(i!=0)
            cout<<" ";
        //-1必不可少
        cout<<selfs[ids[i]-1];
    }
    cout<<endl;

    return 0;
}


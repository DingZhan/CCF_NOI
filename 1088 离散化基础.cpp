#include <iostream>
#include <algorithm>

using namespace std;

//定义数字顺序和数字值的结构体
struct Order
{
    int id;     //第id个数字
    int value;   //该数字的值
};

//定义比较函数
bool Compare(const Order& a, const Order& b)
{
    return a.value<b.value;
}

//最多order数
#define MAX_N 10001
int main ()
{
    int N, i;
    //选手Order数组
    Order orders[MAX_N];
    //ranks是每个数字的最终排名数组, rank是上一个值的排名，lastValue是上一个值
    int ranks[MAX_N], rank, lastValue;
    //读入总的数字数目
    cin>>N;
    //读入N个数字，加到orders数组中
    for(i=0; i<N; ++i)
    {
        cin>>orders[i].value;
        orders[i].id = i;
    }
    //根据value快速排序
    sort(orders, orders+N, Compare);

    //初始化第一个元素排名第一
    rank = 1;
    //第一的元素值
    lastValue = orders[0].value;
    //设置ranks数组
    for(i=0; i<N; ++i)
    {
        //如果当前元素值和上一个元素值不同，则更新rank，更新lastValue
        if(orders[i].value!=lastValue)
        {
            ++rank;
            lastValue = orders[i].value;
            //设置orders[i].id这个编号的rank
            ranks[orders[i].id] = rank;
        }
        else
            //设置orders[i].id这个编号的rank
            ranks[orders[i].id] = rank;
    }
    //打印结果
    for(i=0; i<N; ++i)
    {
        if(i!=0)
            cout<<" ";
        cout<<ranks[i];
    }
    cout<<endl;

    return 0;
}


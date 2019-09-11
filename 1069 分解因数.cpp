#include <iostream>

using namespace std;

#define MAX_LEN 10000

//因子分解递归函数，递归条件是因子分解后的左边因子不能大于右边的因子，所以这里我们借助一个数组存储因子
//start是n的因子起始搜索大小
void Splitter(int n, int start, int r[], int rlen, int& count)
{
    //如果待分解的数n小于等于start值（因子），则递归终结
    if(n<=start)
    {
        //例如5*2是不允许的,即分解后的左边因子不能大于右边的因子
        if(rlen && n!=1 && r[rlen-1]>n)
            return;
        //把剩下的非1的因子加到因子数组最后
        if(rlen && n!=1)
            r[rlen++] = n;
        //累加结果
        ++count;

        //打印解决方案
        /*
        int i;
        for(i=0; i<rlen; ++i)
        {
            if(i!=0)
                cout<<"*";
            cout<<r[i];
        }
        cout<<endl;
        */
        return;
    }
    int i;
    //遍历从start开始的n的所有因子，找到一个因子就递归分解
    for(i=start; i<=n; ++i)
    {
        //找到一个因子，递归分解
        if(n%i==0)
        {
            //把因子i存入到因子数组中
            r[rlen] = i;
            //递归调用，此时n变成了n/i, start变成i, rlen要累加一个，count不需要变化
            Splitter(n/i, i, r, rlen+1, count);
        }
    }
}

int main()
{
    int n, a, i, count;
    //因子分解后存储到r数组中，rlen是数组实际存储的因子数
    int r[MAX_LEN], rlen=0;
    //读入n个测试用列
    cin>>n;
    for(i=0; i<n; ++i)
    {
        //读入一个待分解的a
        cin>>a;
        //初始化因子分解方案为0
        count = 0;
        //初始化因子数组元素个数为0
        rlen = 0;
        //递归分解因子
        Splitter(a, 2, r, rlen, count);
        //打印结果
        cout<<count<<endl;
    }
}

#include <iostream>

using namespace std;

/*测试用例
3
4 4 0
*/

//最多100颗糖果
#define MAX_N 101
#define INFINITE -100000
int main ()
{
    int n, i, id;
    //每种颜色的糖果价值
    int values[5]={5, INFINITE, 10, 7, 1};
    //每种颜色的糖果附加值
    int add[5]={0, 0, 1, 0, -2};
    //当前总和，最大总和，当前附加值
    int sum=0, maxSum=0, bonus=0;
    //读取n个糖果
    cin>>n;
    for(i=0; i<n; ++i)
    {
        //读取糖果颜色
        cin>>id;
        //如果不是黄色，就尝试累加当前糖果价值+当前附加值
        if(values[id]!=INFINITE)
        {
            sum+=values[id]+bonus;
            //得到下一次的附加值
            bonus = add[id];
        }
        //更新最大总和
        if(sum>maxSum)
            maxSum=sum;
        //如果当前之和sum + 下一个bonus为负，则重置sum和bonus为0
        if(sum+bonus<0)
        {
            sum = 0;
            bonus = 0;
        }
    }
    //打印最大总和
    cout<<maxSum<<endl;

    return 0;
}

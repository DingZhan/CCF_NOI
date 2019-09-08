#include <iostream>

using namespace std;

//要将N分解成若干个自然数的和，最多分解成N份，我们将每个加数都存到一个数组中
#define MAX_N 21

//递归分解函数
//将n分解到数组r中，rlen是数组r中实际元素个数
//r数组中左边元素值小于右边元素值
void Decompose(int n, int r[], int rlen)
{
    int i;
    //递归退出条件，待分解的值已经为零
    if(n==0)
    {
        //如果数组长度为1，会打出一个数字，不符合题目要求
        if(rlen>1)
        {
            //打印数组中元素的累加表达式
            for(i=0; i<rlen; ++i)
            {
                if(i!=0)
                    cout<<"+";
                cout<<r[i];
            }
            cout<<endl;
        }
        //退出递归
        return;
    }
    //待分解的n值非0，我们要在当前r[rlen]位置塞入一个值，这个值必须大于数组元素r[rlen-1]的值
    //所以用个start表示r[rlen]的起始值，终止值就是n
    int start=1;
    if(rlen)
        start = r[rlen-1];
    for(i=start; i<=n; ++i)
    {
        //设置数组中当前元素值为i
        r[rlen] = i;
        //递归分解剩下的值到数组右边去
        Decompose(n-i, r, rlen+1);
    }
}

int main ()
{
    int n, r[MAX_N], rlen=0;
    cin>>n;
    //递归调用分解函数，一开始数组中没有存入元素所以rlen=0
    Decompose(n, r, rlen);
    return 0;
}

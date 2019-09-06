#include <iostream>
#include <memory.h>

using namespace std;
#define MAX_M 11

/* 这是7，3这个测试用例篮子内苹果的摆放方法，可以看到左边篮子内苹果数不小于右边篮子内苹果数
7 3
7 0 0
6 1 0
5 2 0
5 1 1
4 3 0
4 2 1
3 3 1
3 2 2
*/

//这里使用组合的递归算法+简单的贪心算法
//我们将篮子放成一排，要求左边篮子内的苹果数目不小于右边篮子中的苹果数目，从而构成题目的要求条件

//这里使用组合递归算法：参数M是剩下的苹果数，baskets是篮子数组，里面存放的是每个篮子内苹果的数目，N是篮子总数目，
//curBasketID是当前要摆放苹果的篮子编号, count是合法结果的计数器
void Combination(int M, int baskets[], int N, int curBasketID, int& count)
{
    //如果当前要摆放苹果的篮子是最后一个篮子
    if(curBasketID==N-1)
    {
        //如果剩下的苹果数目超过了上一个编号的篮子中苹果数目，则这不是一个合法的摆放方法
        if(curBasketID && M>baskets[curBasketID-1])
            return;
        //合法结果计数器加1
        ++count;
        baskets[N-1] = M;
        /*
        int i;
        for(i=0; i<N; ++i)
        {
            cout<<baskets[i]<<" ";
        }
        cout<<endl;
        */
        //结束递归
        return;
    }

    int i;
    //当前篮子内可以摆放苹果的数目是从M到0
    for(i=M; i>=0; --i)
    {
        //如果当前篮子内即将摆放的苹果数目超过左边篮子内苹果数目，则不合法，循环继续
        if(curBasketID && i>baskets[curBasketID-1])
            continue;
        //将i个苹果放入当前篮子
        baskets[curBasketID] = i;
        //递归处理剩下的苹果到右边的篮子，剩下M-i苹果，右边篮子编号：curBasketID+1
        Combination(M-i, baskets, N, curBasketID+1, count);
    }
}

int main()
{
    int M, N, t, i, baskets[MAX_M] ={0}, count;
    cin>>t;
    for(i=0; i<t; ++i)
    {
        //读入苹果数目和篮子数目
        cin>>M>>N;
        //初始化篮子内苹果数都为0
        memset(baskets, 0, sizeof(baskets));
        //初始化解决方案为0
        count = 0;
        //调用组合算法
        Combination(M, baskets, N, 0, count);
        cout<<count<<endl;
    }
}

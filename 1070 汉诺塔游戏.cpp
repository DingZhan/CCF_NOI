#include <iostream>

using namespace std;

#define MAX_N 21

/*经典Hanoi递归函数声明如下：
void Hanoi(int n, char src, char medium, char des)
这里为了实现打印步骤数，需要加入最后一个参数step；
为了实现打印移动盘子的编号，加了一个盘子数组参数，表示当前src上所有盘子的编号
*/
void Hanoi(int n, int disks[], char src, char medium, char des,int &step)
{
    //如果src柱子上只剩一个盘子，则直接把它移动到des上
    if(n==1)
    {
        cout<<step<<".Move "<<disks[0] <<" from "<<src<<" to "<<des<<endl;
        ++step;
        return;
    }
    //否则，把src上n-1个盘子移动到medium柱子上，当然要借助于des柱子
    Hanoi(n-1, disks, src, des, medium, step);
    //此时src柱子上只剩一个盘子，把它移动到des柱子上，这里盘子编号是disks[n-1]而不是disks[0]
    cout<<step<<".Move "<<disks[n-1]<<" from "<<src<<" to "<<des<<endl;
    ++step;
    //把medium上n-1个盘子移动到des柱子上，当然要借助于src柱子
    Hanoi(n-1, disks, medium, src, des, step);
}

int main( void )
{
    int n, i, step=1, disks[MAX_N];
    //读入盘子数
    cin>>n;
    //初始化盘子数字编号
    for(i=0; i<n; ++i)
        disks[i] = i+1;
    //递归调用
    Hanoi(n, disks, 'a', 'b', 'c', step);

    return 0;
}


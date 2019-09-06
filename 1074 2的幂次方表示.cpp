#include <iostream>
#include <algorithm>

using namespace std;

/*测试用例
3
2+2(0)
7
2(2)+2+2(0)
8
2(2+2(0))
137
2(2(2)+2+2(0))+2(2+2(0))+2(0)
*/

//2的幂次方表示, 用递归函数解决这个问题
//函数只有一个参数，就是待分解的n
//主体思想就是n = left + right
//其中left = 2^c, c是可能的最大值
//递归调用Expo(n) = Expo(c) + Expo(n-left)
void Expo(int n)
{
    //处理特殊情况
    if(n==0)
        return;
    //n=2时，根据定义就打印个2
    if(n==2)
    {
        cout<<"2";
        return;
    }
    //n=1时，根据定义打印2(0)，即2^0
    else if(n==1)
    {
        cout<<"2(0)";
        return;
    }
    //其他普通情况，其中left是小于等于n的最大的2的幂结果
    //例如137的left值就是128， 66的left值就是64
    //而变量c就是2^c == left,即需要递归分解的幂值，
    //也就是后续还需要将c进行分解
    int c=0, left=1, nn=n;
    while(nn!=1)
    {
        nn/=2;
        ++c;
        left*=2;
    }
    //如果left值为2，需要特殊处理，因为这里不能打印括号
    if(left==2)
        cout<<2;
    else
    {
        //否则先打印个2，随后再打印左括号
        cout<<2<<"(";
        //递归调用c，而不是left
        Expo(c);
        //再打印右括号
        cout<<")";
    }
    //n = left + right，如果right不为0
    //则先打印个+号，然后递归调用
    if(n-left!=0)
    {
        cout<<"+";
        Expo(n-left);
    }
}
int main ()
{
    int n;
    cin>>n;
    Expo(n);
}

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int t, n, i, j, A, id;
    //B轨道中车厢序号用队列表示
    queue<int> B;
    //C轨道中车厢序号用堆栈表示
    stack<int> C;
    //每个测试用例是否是可能的调度结果
    bool bSucc;
    //t个测试用例
    cin>>t;
    //读入t个测试用例
    for(i=0; i<t; ++i)
    {
        //读入车厢数
        cin>>n;
        //初始化是可能的调度结果
        bSucc=true;
        //A轨道中车厢序号是从1到n，所以初始化为1
        A = 1;
        //读入B轨道中车厢序号
        for(j=0; j<n; ++j)
        {
            cin>>id;
            //invalid data
            if(id>n||id<0)
            {
                bSucc=false;
                continue;
            }
            B.push(id);
        }
        //如果有无效数据，则不可能是调度结果
        if(!bSucc)
        {
            cout<<"Impossible\n";
            continue;
        }
        //A轨道中车厢序号是从1到n
        while(A<=n)
        {
            //如果A轨道最前面的车厢号和B轨道最前面的车厢号一样，则都往后挪一些（对子）
            if(!B.empty() && B.front()==A)
            {
                //从B队列前面一个元素
                B.pop();
                //同时，A车厢序号往后挪
                ++A;
            }
            //如果C轨道中车厢非空，而C堆栈顶部元素和B最前面元素一样，则都往后挪一些（对子）
            else if(!C.empty() && C.top()==B.front())
            {
                //C弹出一个元素
                C.pop();
                //B弹出一个元素
                B.pop();
            }
            else
            {
                //否则把当前A轨道车厢开进C轨道（堆栈）中
                C.push(A);
                //A轨道车厢编号进一个
                A++;
            }
        }
        //开始比较C堆栈和B队列顶端元素
        while(!C.empty())
        {
            if(C.top()!=B.front())
                break;
            C.pop();
            B.pop();
        }
        //比较结束后如果堆栈C或队列B不为空，则标记为失败
        if(!C.empty() || !B.empty())
            bSucc=false;
        if(bSucc)
            cout<<"Possible\n";
        else
            cout<<"Impossible\n";
    }
    return 0;
}

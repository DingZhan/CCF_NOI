#include <iostream>
//用list表示一个链表
#include <list>
using namespace std;

//最大数据量
#define MAX_N 5002

int main()
{
    int n, m, i, a, b;
    bool flag;
    //这个题目必须禁止IO同步，否则有超时
    std::ios::sync_with_stdio(false);
    //用list表示一个链表
    list<int> data;
    //用一个迭代器访问链表
    list<int>::iterator it;

    //读入元素个数
    cin>>n;
    //读入n个元素，一一加入链表
    for(i=0; i<n; ++i)
    {
        cin>>a;
        //一一加入链表尾部
        data.insert(data.end(), a);
    }

    //读入操作数
    cin>>m;
    //读入m个操作
    for(i=0; i<m; ++i)
    {
        //读入操作类型和操作数值
        cin>>a>>b;
        //把b挪到链表尾部
        if(a==0)
        {
            //遍历链表，把b挪到链表尾部
            for(it=data.begin(); it!=data.end(); ++it)
            {
                if(*it==b)
                {
                    //先把b从链表里删了
                    data.erase(it);
                    //然后把b加到链表尾部
                    data.insert(data.end(), b);
                    break;
                }
            }
        }
        else //不打印b而已，注意空格要前置打印
        {
            //是否打印空格的标记
            flag=0;
            for(it=data.begin(); it!=data.end(); ++it)
            {
                //碰到b不打印
                if(*it==b)
                    continue;
                if(flag)
                    cout<<" ";
                cout<<*it;
                flag = 1;
            }
            cout<<endl;
        }
    }

    return 0;
}

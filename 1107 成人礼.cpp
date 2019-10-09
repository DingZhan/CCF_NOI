#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    int n, i, a;
    //用链表解决前后入座的问题
    list<string> ids;
    //迭代器，用来访问链表
    list<string>::iterator it;
    string name;

    //读入总人数
    cin>>n;
    //读入n个人入座的信息
    for(i=0; i<n; ++i)
    {
        //从左或右入座，名字
        cin>>a>>name;
        //左入座，即插入链表头
        if(a==0)
            ids.insert(ids.begin(), name);
        else//右入座，插入链表尾部
            ids.insert(ids.end(), name);
    }

    //用迭代器访问链表，打印结果
    for(it=ids.begin(); it!=ids.end(); ++it)
    {
        cout<<*it<<endl;
    }

    return 0;
}


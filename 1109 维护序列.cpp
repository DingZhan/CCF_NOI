#include <iostream>
#include <list>

using namespace std;

//本题序列用链表表示，链表用list表示

int main()
{
    int i, n, m, a, j, v;
    //list做链表
    list<int> datas;
    //迭代器
    list<int>::iterator it;

    //读入序列长度
    cin>>n;
    //把序列装入链表
    for(i=0; i<n; ++i)
    {
        cin>>a;
        //元素插入到链表尾部
        datas.insert(datas.end(), a);
    }

    //读入操作次数
    cin>>m;
    //读入操作信息
    for(i=0; i<m; ++i)
    {
        //操作信息
        cin>>a;
        //查询第j个元素的值
        if(a==1)
        {
            cin>>j;
            //注意j>1
            for(it=datas.begin(); j>1; ++it, --j);
            //查询
            cout<<*it<<endl;
        }
        //在第j个元素前插入值
        else if(a==2)
        {
            cin>>j>>v;
            //注意j>1
            for(it=datas.begin(); j>1; ++it, --j);
            //插到it前面
            datas.insert(it, v);
        }
        //删除第j个元素
        else
        {
            cin>>j;
            //注意j>1
            for(it=datas.begin(); j>1; ++it, --j);
            //删除
            datas.erase(it);
        }
    }
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//商品结构体
struct Goods
{
    int value; //价值
    int cost;  //花费
    int id;     //编号
};

//比较函数：物品按照价值从大到小排序，价值相等的物品按照花费从小到大排序
bool Compare(const Goods& a, const Goods &b)
{
    //价值大的排前面
    if(a.value>b.value)
        return true;
    //价值小的排后面
    else if(a.value<b.value)
        return false;
    else //价值相同时，按照花费从小到大排序
        return a.cost<b.cost;
}
int main ()
{
    //商品数组
    int n, i;
    vector<Goods> goods;
    Goods v;

    //读入商品总数目n
    cin>>n;
    //读入n个商品
    for(i=0; i<n; ++i)
    {
        //读入商品价值和花费
        cin>>v.value>>v.cost;
        //设置该商品编号
        v.id = i+1;
        //添加到vector容器（数组）中
        goods.push_back(v);
    }
    //排序
    sort(goods.begin(), goods.end(), Compare);

    //打印排序后商品编号
    for(i=0; i<n; ++i)
    {
        if(i!=0)
            cout<<" ";
        cout<<goods[i].id;
    }
    cout<<endl;
    return 0;
}

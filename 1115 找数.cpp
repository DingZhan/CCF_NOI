#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//改进的二分查找法，因为要查询多次，所以需要将原始查询顺序进行一次排序，
//从而降低后续查询的end的范围

//查询结构体
struct XOrder
{
    int x; //待查询的x的值
    int order; //待查询的序号
};

//待查询的x值进行排序的比较函数，较大的x排在前面
bool SortByX(const XOrder& a, const XOrder& b)
{
    return a.x>b.x;
}

int main()
{
    //取消I/O同步
    std::ios::sync_with_stdio(false);
    int i, n, m, x, b, e, mi, last;
    //data是原始输入的已排好序的数组
    vector<int> data;
    //xs是查询数组
    vector<XOrder> xs;
    //results是结果数组
    vector<int> results;

    //输入原始数组大小和查询次数
    cin>>n>>m;
    //分配原始数组
    data.resize(n);
    //读入原始数组
    for(i=0; i<n; ++i)
        cin>>data[i];
    //分配查询结构体数组
    xs.resize(m);
    //分配查询结果数组
    results.resize(m);
    //读入m次查询
    for(i=0; i<m; ++i)
    {
        //设置本次查询编号
        xs[i].order = i;
        //读入查询值
        cin>>xs[i].x;
    }
    //对查询数组进行排序
    sort(xs.begin(), xs.end(), SortByX);
    //初始化二分查找法的end位置为数组最后一个元素，后续查询不再初始化成数组最后位置，
    //而是要设置成上一次的middle位置
    e = n-1;
    //开始查询
    for(i=0; i<m; ++i)
    {
        //查询范围的begin设置为0
        b = 0;
        //待查询的x值
        x = xs[i].x;
        //初始化满足小于条件的最后一个元素值为-1
        last = -1;
        //开始二分查找
        while(b<=e)
        {
            //设置middle
            mi = (b+e)/2;
            //如果找到则退出
            if(data[mi]==x)
            {
                last = data[mi];
                break;
            }
            //降低上限
            else if(data[mi]>x)
                e = mi-1;
            //提高下限
            else if(data[mi]<x)
            {
                b = mi+1;
                //设置最后一个满足条件的值
                last = data[mi];
            }
        }
        //保存查询结果
        results[xs[i].order] = last;
        //设置下一轮的查询上限end为本次的middle
        e = mi;
    }
    //打印查询结果
    for(i=0; i<m; ++i)
        cout<<results[i]<<"\n";
    return 0;
}

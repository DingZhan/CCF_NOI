#include <iostream>
#include <algorithm> //sort, lower_bound
#include <cstring>

using namespace std;

//最多100条记录
#define MAX_N 101
class Shape
{
public:
    //形状类型
    char type;
    //形状参数
    int r, a, b;
    //类成员函数：打印
    void Print()
    {
        if(type=='T')
            cout<<"Triangle "<<a<<endl;
        else if(type=='C')
            cout<<"Circle "<<r<<endl;
        else if(type=='R')
            cout<<"Rectangle "<<a<<" "<<b<<endl;
    }
};
int main ()
{
    int n, Q, i, id;
    //形状数组
    Shape shapes[MAX_N];
    //用来忽略一个换行符
    string str;
    //读入形状数和查询条数
    cin>>n>>Q;
    //忽略换行符
    std::getline(cin, str);
    for(i=0; i<n; ++i)
    {
        //读入形状类型字符
        cin>>shapes[i].type;
        //三角形
        if(shapes[i].type=='T')
            cin>>shapes[i].a;
        //圆形
        else if(shapes[i].type=='C')
            cin>>shapes[i].r;
        //矩形
        else if(shapes[i].type=='R')
            cin>>shapes[i].a>>shapes[i].b;
    }
    for(i=0; i<Q; ++i)
    {
        cin>>id;
        shapes[id-1].Print();
    }

    return 0;
}

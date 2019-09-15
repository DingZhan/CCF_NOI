#include <iostream>
#include <algorithm> //sort, lower_bound
#include <cstring>

using namespace std;

//最多100条记录
#define MAX_N 101

//车辆信息结构体
struct Vehicle
{
    char S[8]; //车牌
    int V;     //排量
    int W;      //载重
    int type;   // 0 name, 1 phone
    char name[21]; //车主名字/家庭电话
    int id;     //在数组中的索引
};

//车牌+车辆信息数组索引号的结构体
struct S
{
    char s[8];  //车牌
    int id;     //在Vehicle数组中的索引
};

//按车牌的字典序进行排序
bool SortByS(const S& a, const S& b)
{
    return strcmp(a.s, b.s)<0;
}

int main ()
{
    //车辆结构体数组
    Vehicle vehicles[MAX_N];
    //大于等于V/W比例的车辆数, 桶原理,桶实际最大为101
    int vws[1000]={0};
    //车牌结构体数组，用二分法搜索车辆信息
    S ss[MAX_N], *ts, tempS;
    int i, j, n, Q, op, id, k, vw;

    //读入总车辆数
    cin>>n;
    //读入n辆车的信息
    for(i=0; i<n; ++i)
    {
        cin>>vehicles[i].S>>vehicles[i].V>>vehicles[i].W>>
            vehicles[i].type>>vehicles[i].name;
        //设置在vehicles数组中索引号
        vehicles[i].id = i;

        //设置车牌结构体中车牌信息
        strcpy(ss[i].s, vehicles[i].S);
        //设置在vehicles数组中索引号
        ss[i].id = i;

        //计算vw比例
        vw = vehicles[i].V/vehicles[i].W;
        //累加到[0, vw]桶中
        for(j=0; j<=vw; ++j)
            ++vws[j];
    }

    //对所有车牌进行字典排序
    sort(ss, ss+n, SortByS);

    //读入查询总记录条数Q
    cin>>Q;
    //读入Q条查询信息
    for(i=0; i<Q; ++i)
    {
        //读入查询类型
        cin>>op;
        //根据id查询车牌
        if(op==1)
        {
            cin>>id;
            id-=1;
            cout<<vehicles[id].S<<endl;
        }
        //根据车牌查车主名字或电话
        else if(op==2)
        {
            //读入待查询的车牌到临时结构体temp中的s中
            cin>>tempS.s;
            //用二分搜索法获得对应车牌在vehicles数组中的位置
            ts = lower_bound(ss, ss+n, tempS, SortByS);
            //如果找到该记录
            if(ts!=ss+n && !SortByS(tempS, *ts))
            {
                //得到对应车牌在vehicles数组中的索引
                id = ts->id;
                cout<<vehicles[id].name<<endl;
            }
        }
        //根据vw比率查询车辆数
        else if(op==3)
        {
            cin>>k;
            if(k<1000)
                cout<<vws[k]<<endl;
            else
                cout<<0<<endl;
        }
    }

    return 0;
}

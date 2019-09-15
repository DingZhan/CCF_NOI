#include <iostream>
#include <algorithm> //sort, lower_bound
#include <cstring>

using namespace std;

//最多100条记录
#define MAX_N 101

//建造者信息（不含名字）
struct Builder
{
    int value;  //刻上的数值
    int id;     //该数值在原始文字中的索引号
};

int main ()
{
    //values用来存储原始文字中的所有数字
    int n, Q, i, j, values[MAX_N], nameID, start, end, sum;
    //三个建造者用三个独立的数组， 0 Alice, 1 Bob, 2 Cathy
    Builder builders[3][MAX_N];
    //三个建造者各自刻的数字总个数
    int lens[3]={0};
    string name;

    //读入数字总个数和空位个数
    cin>>n>>Q;

    //读入所有数字
    for(i=0; i<n; ++i)
        cin>>values[i];

    //读入所有数字对应的建造人
    for(i=0; i<n; ++i)
    {
        cin>>name;
        //读入的建造人对应的二维数组的第一维度索引号:0,1,2,
        if(name=="Alice")
            nameID = 0;
        else if(name=="Bob")
            nameID = 1;
        else
            nameID = 2;
        //把数字索引号加入到数组中
        builders[nameID][lens[nameID]].id = i+1;
        //把值加入到数组中
        builders[nameID][lens[nameID]].value = values[i];
        //三个建造者各自刻的数字总个数累加
        ++lens[nameID];
    }

    //读入Q个查询
    for(i=0; i<Q; ++i)
    {
        //读取名字、开始索引号和终止索引号
        cin>>name>>start>>end;
        if(name=="Alice")
            nameID = 0;
        else if(name=="Bob")
            nameID = 1;
        else
            nameID = 2;
        //开始累加求和
        sum = 0;
        for(j=0; j<lens[nameID]; ++j)
        {
            if(builders[nameID][j].id<start)
                continue;
            if(builders[nameID][j].id>end)
                break;
            sum+= builders[nameID][j].value;
        }
        cout<<sum<<endl;
    }

    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

//初始状态最多有1000杯溶液，最多有1000组实验，所以最高峰有2000杯溶液出现
#define MAX_N 2002

int main()
{
    //溶液质量数组M，溶液体积数组V
    int M[MAX_N], V[MAX_N];
    int i, j, x, m, v, mt,L, R, sumM, sumV, n;
    //操作类型
    char op;

    //读入初始溶液杯数
    cin>>n;
    //读入n个溶液质量和体积数据
    for(i=1; i<=n; ++i)
        cin>>M[i]>>V[i];
    //读入操作次数
    cin>>mt;
    //读入所有操作信息
    for(i=0; i<mt; ++i)
    {
        //读入操作类型
        cin>>op;
        //混合溶液实验
        if(op=='E')
        {
            //读入混合溶液的起始和终止杯子索引号
            cin>>L>>R;
            //初始化区间累加质量和体积为0
            sumM = sumV=0;
            //混合溶液
            for(j=L; j<=R; ++j)
            {
                sumM+=M[j];
                sumV+=V[j];
                //不补充溶液才要清空
            //    M[j] = 0;
            //    V[j] = 0;
            }
            //输出混合后的液体密度
            cout<<fixed<<setprecision(3)<<(sumM+0.)/sumV<<endl;
        }
        //插入一杯新溶液
        else if(op=='I')
        {
            //新溶液插入位置，质量和体积
            cin>>x>>m>>v;
            //x之后的溶液都往后挪一个位置
            for(j=n+1; j>x+1; --j)
            {
                M[j] = M[j-1];
                V[j] = V[j-1];
            }
            //加入新溶液
            M[x+1] = m;
            V[x+1] = v;
            //溶液数目加1
            ++n;
        }
        //删除一杯溶液
        else if(op=='D')
        {
            //读入待删除溶液杯子索引号
            cin>>x;
            //x之后的溶液都向前挪一个位置
            for(j=x; j<n; ++j)
            {
                M[j] = M[j+1];
                V[j] = V[j+1];
            }
            //溶液数目减1
            --n;
        }
    }
    return 0;
}

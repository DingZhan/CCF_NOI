#include <iostream>

using namespace std;

//经典二分查找问题
//数组最大长度
#define MAX_N 100001
//元素最大值
#define MAX_DIS 1000000000
int main()
{
    int n, i, m, v, nearV, middle, low, high, minDis, cv;
    //数组存储非降序排列的数据
    int datas[MAX_N];
    //读入数组元素个数
    cin>>n;
    //读入数组元素
    for(i=0; i<n; ++i)
        cin>>datas[i];
    //读入查询次数
    cin>>m;
    //查询
    for(i=0; i<m; ++i)
    {
        //读入待查询的值
        cin>>v;
        //初始化和待查询值的最小距离
        minDis = MAX_DIS;
        //二分查找初始化
        low = 0;
        high = n-1;
        middle = (low+high)/2;
        while(low<=high)
        {
            //当前元素值为cv
            cv = datas[middle];
            //如果cv比待查询值v大
            if(cv>v)
            {
                //比较最小距离值，如果最小距离比当前距离大，则刷新最小距离
                if(minDis>cv-v)
                {
                    //刷新最小距离
                    minDis = cv-v;
                    //刷新最近的值
                    nearV = cv;
                }
                high = middle-1;
            }
            else if(cv<v)//如果cv比待查询值v小
            {
                //比较最小距离值，如果最小距离比当前距离大或者等于，则刷新最小距离
                //“若有多个值满足条件，输出最小的一个”，所以这里要加等于情况
                if(minDis>=v-cv)
                {
                    //刷新最小距离
                    minDis = v-cv;
                    //刷新最近的值
                    nearV = cv;
                }
                low = middle+1;
            }
            else //在数组中找到了该值，直接退出搜索
            {
                nearV = v;
                minDis = 0;
                break;
            }
            //下一次搜索
            middle = (low+high)/2;
        }
        //打印最近值
        cout<<nearV<<endl;
    }
    return 0;
}


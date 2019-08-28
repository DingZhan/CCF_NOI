#include <iostream>

using namespace std;

int main()
{
    //二维数组，用来存储方阵结果
    int mat[5][5], maxV;
    int i, j, k;
    bool bSucc=false;
    //读入方阵
    for(i=0; i<5; ++i)
    {
        for(j=0; j<5; ++j)
            cin>>mat[i][j];
    }
    //逐行搜索每行的最大值
    for(i=0; i<5; ++i)
    {
        //在第i行搜索最大元素值
        maxV = mat[i][0];
        for(j=1; j<5; ++j)
        {
            if(maxV<mat[i][j])
                maxV = mat[i][j];
        }
        //一行里可能有多个相同的最大值，所以得再来遍历一遍
        for(j=0; j<5; ++j)
        {
            if(maxV==mat[i][j])
            {
                //测试mat[i][j]是否是第j列最小值
                for(k=0; k<5; ++k)
                {
                    if(mat[k][j]<maxV)
                        break;
                }
                //找到了鞍点
                if(k==5)
                {
                    cout<<i+1<<" "<<j+1<<" "<<maxV<<endl;
                    bSucc = true;
                }
            }
        }
    }
    //如果没找到鞍点
    if(!bSucc)
        cout<<"not found\n";
    return 0;
}


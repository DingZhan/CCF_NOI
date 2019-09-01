#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 101
#define INFINITE 100000000

int main( void )
{
    //矩阵A，因为最大元素值不超过100，所以用char类型节省内存
    char A[MAX_N][MAX_N], B[MAX_N][MAX_N];
    int i, j, m, n, r, s, v, ii, jj, minV = INFINITE, minI, minJ;

    //读入A矩阵行和列
    cin>>m>>n;
    //读入A矩阵，因为矩阵是用char表示，所以先用一个整数中转一下
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            cin>>v;
            A[i][j] = v;
        }
    }

    //读入B矩阵行和列
    cin>>r>>s;
    //读入B矩阵，因为矩阵是用char表示，所以先用一个整数中转一下
    for(i=0; i<r; ++i)
    {
        for(j=0; j<s; ++j)
        {
            cin>>v;
            B[i][j] = v;
        }
    }

    //在矩阵A中的行搜索范围[0, m-r]
    for(i=0; i<=m-r; ++i)
    {
        //在矩阵A中的列搜索范围[0, n-s]
        for(j=0; j<=n-s; ++j)
        {
            //矩阵A中r*s子矩阵与B矩阵的绝对值差值的累加和
            v=0;
            for(ii=0; ii<r; ++ii)
            {
                for(jj=0; jj<s; ++jj)
                {
                    v+=abs(A[i+ii][j+jj]-B[ii][jj]);
                }
            }
            //更新最小值，记录当前最小子矩阵子矩阵位置<minI, minJ>
            if(v<minV)
            {
                minV = v;
                minI = i;
                minJ = j;
            }
        }
    }
    //打印A中的最小子矩阵
    for(ii=0; ii<r; ++ii)
    {
        for(jj=0; jj<s; ++jj)
        {
            if(jj!=0)
                cout<<" ";
			//应为矩阵A用char表示，所以这里要强制转换成整形
            cout<<(int)A[minI+ii][minJ+jj];
        }
        cout<<endl;
    }
    return 0;
}


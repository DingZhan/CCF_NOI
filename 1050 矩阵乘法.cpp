#include <iostream>

using namespace std;

#define MAX_N 101

int main( void )
{
    int n, m, k, i, j, t;
    int A[MAX_N][MAX_N],B[MAX_N][MAX_N],C[MAX_N][MAX_N];

    cin>>n>>m>>k;

    //读入矩阵A
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
            cin>>A[i][j];
    }

    //读入矩阵B
    for(i=0; i<m; ++i)
    {
        for(j=0; j<k; ++j)
            cin>>B[i][j];
    }


    //C = A*B
	//n*m阶的矩阵A乘以m*k阶的矩阵B得到的矩阵C 是n*k阶的，
	//且C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + …… +A[i][m-1]*B[m-1][j](C[i][j]表示C矩阵中第i行第j列元素)。
    for(i=0; i<n; ++i)
    {
        for(j=0; j<k; ++j)
        {
            C[i][j] = 0;
            for(t=0; t<m; ++t)
                C[i][j]+=A[i][t]*B[t][j];
            if(j!=0)
                cout<<" ";
            cout<<C[i][j];
        }
        cout<<endl;
    }
    return 0;
}


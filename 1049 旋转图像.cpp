#include <iostream>

using namespace std;

#define MAX_MN 101

int main( void )
{
    unsigned char mat[MAX_MN][MAX_MN];
    int i, j, v, m, n;
    cin>>n>>m;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            cin>>v;
            mat[i][j] = v;
        }
    }

    //顺时针寻转90
    //m行
    for(i=0; i<m; ++i)
    {
        //n列
        for(j=0; j<n; ++j)
        {
            if(j!=0)
                cout<<" ";
            //找规律,7原来是[2][0]，现在是[0][0]
            cout<<(int)mat[n-j-1][i];
        }
        cout<<endl;
    }


    /*另外一种更通用的方法，利用二维旋转公式
    |i'|=|cosA  -sinA||i|
    |j'|=|sinA  cosA ||j|
    顺时针90°，即A = -90°
    |i'|=|0   1||i|
    |j'|=|-1  0||j|

    unsigned char matRot[MAX_MN][MAX_MN];
    int ii, jj;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            ii = j;
            jj = n-i-1;
            matRot[ii][jj] = mat[i][j];
        }
    }
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(j!=0)
                cout<<" ";
            cout<<(int)matRot[i][j];
        }
        cout<<endl;
    }
   */
    return 0;
}


#include <iostream>

using namespace std;

#define MAX_N 501
#define MAX_M 501

int main()
{
    int mat[MAX_N][MAX_M], i, j, q, x, y, n, m;
    char op;
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
            cin>>mat[i][j];
    }
    cin>>q;
    for(i=0; i<q; ++i)
    {
        cin>>op>>x>>y;
        --x;
        --y;
        if(op=='C')
        {
            for(j=0; j<m; ++j)
                swap(mat[x][j], mat[y][j]);
        }
        else
        {
            cout<<mat[x][y]<<endl;
        }
    }
    return 0;
}

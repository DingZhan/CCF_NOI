#include <iostream>
#include <iomanip>

using namespace std;

//最大m,n
#define MAX_MN 101

int main( void )
{
    char image1[MAX_MN][MAX_MN],image2[MAX_MN][MAX_MN];
    int i, j, m, n, count=0, p;
    cin>>m>>n;
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            cin>>p;
            image1[i][j] = p;
        }
    }
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            cin>>p;
            image2[i][j] = p;
        }
    }
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(image1[i][j] ==image2[i][j])
                ++count;
        }
    }
    cout<<fixed<<setprecision(2)<<count*100.0/(m*n)<<endl;

    return 0;
}


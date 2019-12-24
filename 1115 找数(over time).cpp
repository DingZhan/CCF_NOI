#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int i, n, m, x, b, e, mi, last;
    vector<int> data;
    cin>>n>>m;
    data.resize(n);
    for(i=0; i<n; ++i)
    {
        cin>>data[i];
    }
    for(i=0; i<m; ++i)
    {
        cin>>x;
        b = 0;
        e = n-1;
        last = -1;
        while(b<=e)
        {
            mi = (b+e)/2;
            if(data[mi]==x)
            {
                last = data[mi];
                break;
            }
            else if(data[mi]>x)
                e = mi-1;
            else if(data[mi]<x)
            {
                b = mi+1;
                last = data[mi];
            }
        }
        cout<<last<<endl;
    }
}

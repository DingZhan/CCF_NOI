#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct XOrder
{
    int x;
    int order;
};
bool SortByX(const XOrder& a, const XOrder& b)
{
    return a.x>b.x;
}
bool SortByOrder(const XOrder& a, const XOrder& b)
{
    return a.order<b.order;
}
int main()
{
    int i, n, m, x, b, e, mi, last;
    vector<int> data, results;
    vector<XOrder> xs;

    cin>>n>>m;
    data.resize(n);
    for(i=0; i<n; ++i)
    {
        cin>>data[i];
    }
    xs.resize(m);
    results.resize(m);
    for(i=0; i<m; ++i)
    {
        xs[i].order = i;
        cin>>xs[i].x;
    }
    sort(xs.begin(), xs.end(), SortByX);
    e = n-1;
    for(i=0; i<m; ++i)
    {
        b = 0;
        last = -1;
        x = xs[i].x;
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
        results[xs[i].order] = last;
        e = mi;
    }
    for(i=0; i<m; ++i)
        cout<<results[i]<<"\n";
    return 0;
}

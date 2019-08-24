#include <iostream>

using namespace std;

int main()
{
    int n, i, a, max=-1, min=10000;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>a;
        if(a>max)
            max = a;
        if(a<min)
            min = a;
    }
    cout<<max-min<<endl;

    return 0;
}

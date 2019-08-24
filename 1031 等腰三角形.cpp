#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        //每行起始的空格数目就是n-i
        for(j=0; j<n-i; ++j)
            cout<<" ";
        //每行的连续*数目就是2*i-1
        for(j=0; j<2*i-1; ++j)
            cout<<"*";
        cout<<endl;
    }
    return 0;
}

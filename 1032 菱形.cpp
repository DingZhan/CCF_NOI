#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    cin>>n;
    //先打印上半部分包括中间部分
    for(i=1; i<=n; ++i)
    {
        //每行起始的空格数目就是n-i
        for(j=0; j<n-i; ++j)
            cout<<" ";
        //每行的数子就是从1至2*i-1
        for(j=1; j<=2*i-1; ++j)
            cout<<j;
        //打印回车
        cout<<endl;
    }
    //再打印下半部分不包括中间部分
    for(i=n-1; i>=1; --i)
    {
        //每行起始的空格数目就是n-i
        for(j=0; j<n-i; ++j)
            cout<<" ";
        //每行的数子就是从1至2*i-1
        for(j=1; j<=2*i-1; ++j)
            cout<<j;
        cout<<endl;
    }
    return 0;
}

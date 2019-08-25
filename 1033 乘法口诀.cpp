#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    cin>>n;
    //外层循环，共有n行要打
    for(i=1; i<=n; ++i)
    {
        //内层循环共有i个乘法要打
        for(j=1; j<=i; ++j)
        {
            if(j!=1)
                cout<<" ";
            cout<<j<<"*"<<i<<"="<<j*i;
        }
        cout<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main( void )
{
    int a=0, b=1, c, i, n;
    cin>>n;
    if(n==1)
        c = a;
    else if(n==2)
        c = b;
    for(i=3; i<=n; ++i)
    {
        c = a+b;
        a = b;
        b = c;
    }
    cout<<c<<endl;
    return 0;
}


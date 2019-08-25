#include <iostream>

using namespace std;

int main()
{
    int a, b, i, p=1;
    cin>>a>>b;
    for(i=0; i<b; ++i)
    {
        p=p*a%10;
    }
    cout<<p<<endl;

    return 0;
}

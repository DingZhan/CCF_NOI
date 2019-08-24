#include <iostream>

using namespace std;

int gcd(int m, int n)
{
    int c = m%n;
    while(c)
    {
        m = n;
        n = c;
        c = m%n;
    }
    return n;
}

int main()
{
    int m, n, f;
    cin>>m>>n;
    f =  gcd(m, n);
    if(f==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}

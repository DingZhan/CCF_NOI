#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c, i, gold=0, silver=0, bronze = 0;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>a>>b>>c;
        gold+=a;
        silver+=b;
        bronze+=c;
    }
    cout<<gold<<" "<<silver<<" "<<bronze<<" "<<gold+silver+bronze<<endl;
    return 0;
}

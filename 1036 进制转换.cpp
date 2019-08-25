#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin>>n;
    while(n)
    {
        cout<<"shang:"<<n/2<<" yu:"<<n%2<<endl;
        n/=2;
    }

    return 0;
}

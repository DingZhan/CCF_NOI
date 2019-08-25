#include <iostream>

using namespace std;

int main()
{
    int n, sum;
    cin>>n;
    while(n>10)
    {
        sum = 0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        n = sum;
    }

    cout<<n<<endl;
    return 0;
}

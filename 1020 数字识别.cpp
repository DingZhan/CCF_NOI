#include <iostream>

using namespace std;

int main()
{
    int x, digits[4], n=0, i;
    cin>>x;
    while(x)
    {
        digits[n++] = x%10;
        x/=10;
    }
    cout<<n<<endl;
    for(i=n-1; i>=0; --i)
        cout<<digits[i]<<endl;
    return 0;
}

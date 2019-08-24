#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, i, age, sum=0;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>age;
        sum+=age;
    }

    cout<<fixed<<setprecision(2)<<(sum+0.0)/n<<endl;

    return 0;
}

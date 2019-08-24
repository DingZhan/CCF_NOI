#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int sum=0, max=0, min=101, i, a;
    for(i=0; i<10; ++i)
    {
        cin>>a;
        sum+=a;
        if(a>max)
            max = a;
        if(a<min)
            min = a;
    }
    sum=sum-max-min;
    cout<<fixed<<setprecision(3)<<sum/8.0<<endl;
    return 0;
}

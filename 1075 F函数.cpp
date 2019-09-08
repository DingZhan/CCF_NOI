#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//找规律,规律x = sqrt(i+x),x每次更新以下即可
double f(double x, int n)
{
    int i;
    for(i=1; i<=n; ++i)
    {
        x = sqrt(i+x);
    }
    return x;
}

int main ()
{
    int n;
    double x;
    cin>>x>>n;
    cout<<fixed<<setprecision(2)<<f(x, n)<<endl;
    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int w;
    double p;
    cin>>w;
    if(w<=10)
        p = w*0.8+0.2;
    else if(w<=20)
        p = 10*0.8 + (w-10)*0.75+0.2;
    else if(w<=30)
        p = 10*0.8 + 10*0.75+ (w-20)*0.7+0.2;
    else
    {
        cout<<"Fail"<<endl;
        return 0;
    }
    cout<<fixed<<setprecision(2)<<p<<endl;
    return 0;
}


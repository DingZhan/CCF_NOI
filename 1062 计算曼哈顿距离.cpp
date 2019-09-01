#include <iostream>
#include <iomanip> //fixed setprecision
#include <cmath> //fabs

using namespace std;

int main( void )
{
    double x1, y1, x2, y2, dis;
    cin>>x1>>y1>>x2>>y2;
    dis = fabs(x1-x2)+fabs(y1-y2);
    cout<<fixed<<setprecision(3)<<dis<<endl;
    return 0;
}


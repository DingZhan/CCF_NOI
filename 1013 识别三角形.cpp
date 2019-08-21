#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    if(a<b)
        swap(a, b);
    if(a<c)
        swap(a, c);
    if(a>=b+c||b<=0||c<=0)
        cout<<"NO";
    else
    {
        if(a==b && a==c)
            cout<<"Equilateral";
        else if(a*a==b*b+c*c)
            cout<<"Right";
        else
            cout<<"General";
    }
    cout<<endl;
    return 0;
}

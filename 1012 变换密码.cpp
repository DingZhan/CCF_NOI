#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin>>n;
    m = n%123;
    if(m>=97 && m<=122)
        cout<<(char)m;
    else
    {
        m = n%91;
        if(m>=65 && m<=90)
            cout<<(char)m;
        else
            cout<<"*";
    }
    //这题不能加回车，否则就0分
    //cout<<endl;
    return 0;
}


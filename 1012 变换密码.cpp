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
    //���ⲻ�ܼӻس��������0��
    //cout<<endl;
    return 0;
}


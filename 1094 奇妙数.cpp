#include <iostream>

using namespace std;


int main ()
{
    int A=0, B, n, i;
    string op;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>op>>B;
        if(op=="+")
            A = (A*B+B*A)%12345;
        else if(op=="-")
            A = (A+B+A*B)%12345;
        else if(op=="*")
            A = (B*B+A*A)%12345;
        else if(op=="/")
            A = (B-A+B*A)%12345;
        cout<<A<<endl;
    }
    return 0;
}

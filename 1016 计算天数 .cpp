#include <iostream>

using namespace std;

int main()
{
    int days[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}};
    int leap = 0;
    int y, m;
    cin>>y>>m;
    if(y%4==0&&y%100!=0 || y%400==0)
        leap = 1;
    m = m-1;
    cout<<days[leap][m];
    return 0;
}

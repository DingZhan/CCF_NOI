#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int id;
    double price;
    cout<<"[1] apples\n\
[2] pears\n\
[3] oranges\n\
[4] grapes\n\
[0] Exit\n";
    cin>>id;
    switch(id)
    {
    case 0:
        return 0;
    case 1:
        price = 3.0;
        break;
    case 2:
        price = 2.5;
        break;
    case 3:
        price = 4.1;
        break;
    case 4:
        price = 10.2;
        break;
    default:
        //输入其他编号，显示价格为0, 而不是0.0
        cout<<"price=0"<<endl;
        return 0;
        break;
    }
    cout<<"price="<<fixed<<setprecision(1)<<price<<endl;
    return 0;
}

#include <iostream>
#include <string>
#include <sstream> //用istringstream处理输入的字符串

using namespace std;

int main( void )
{
    string str;
    int d, s=0;
    char c;
    //用istringstream流处理输入的字符串
    istringstream iss;
    //得到一行输入
    getline(cin, str);
    //把字符串打包到流里
    iss.str(str);
    while(true)
    {
        //尝试得到下一个整数
        iss>>d;
        //得到下一个整数失败，退出循环
        if(iss.fail())
            break;
        //累加该整数
        s+=d;
        //过滤掉'+'号
        iss>>c;
    }
    cout<<s<<endl;
    return 0;
}


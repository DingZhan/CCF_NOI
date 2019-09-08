#include <iostream>
#include <string>
#include <algorithm> //reverse

using namespace std;


int main ()
{
    //r是X在M进制下的个位数
    int X, M, r;
    //将结果存到s字符串中
    string s;
    cin>>X>>M;
    while(X)
    {
        //得到X取模M后的余数，即M进制的个位数
        r = X%M;
        //如果余数小于等于9，则加入该数字对应的数字字符
        if(r<=9)
            s+='0'+r;
        else//如果余数大于9，则加入该数字对应的字母字符（从'A'开始）
            s+='A'+(r-10);
        //X在M进制下，右移一位
        X/=M;
    }
    //将结果字符串反过来，因为是从X的M进制的个位数开始存储的
    reverse(s.begin(), s.end());
    //打印结果
    cout<<s<<endl;
    return 0;
}

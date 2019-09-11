#include <iostream>
#include <string> //string
#include <algorithm> //sort

using namespace std;

//就是对输入的每行字符串都进行一次内部排序，排序完和最小字符串再进行一次比较
int main()
{
    int n, i;
    string str, minStr;

    //读入n
    cin>>n;
    //读入n个字符串
    for(i=0; i<n; ++i)
    {
        //读入一个字符串
        cin>>str;
        //按字典升序对该字符串进行排序
        sort(str.begin(), str.end());
        //如果该字符串小于最小字符串，更新最小字符串
        if(i==0)
            minStr = str;
        else
        {
            if(minStr>str)
                minStr = str;
        }
    }
    cout<<minStr<<endl;
    return 0;
}

#include <iostream>

using namespace std;

int main ()
{
    string str;
    int i, j;
    //大写字母统计个数放在26个桶里面，maxNum是其中某个字母出现的最多次数
    short buckets[26] = {0}, maxNum;

    //读入四行字符串
    for(i=0; i<4; ++i)
    {
        //读入一行字符串
        getline(cin, str);
        //逐个解析字符
        for(j=0; j<str.size(); ++j)
        {
            //如果是大写字母，则计数
            if(str[j]>='A' && str[j]<='Z')
                ++buckets[str[j]-'A'];
        }
    }

    //统计某个字符出现的最多的次数
    maxNum=0;
    for(i=0; i<26; ++i)
    {
        if(maxNum<buckets[i])
            maxNum = buckets[i];
    }

    //外层循环对应的是总行数
    for(i=0; i<maxNum; ++i)
    {
        //内层循环是用来打印*或者空格
        for(j=0; j<26; ++j)
        {
            //打印前置空格
            if(j!=0)
                cout<<" ";
            //如果当前字母的个数超过第几行数，则打印*号，否则打印空格
            //这个是这道题的重点推论
            if(buckets[j]>=maxNum-i)
                cout<<"*";
            else
                cout<<" ";
        }
        //打印一行的回车
        cout<<endl;
    }

    //打印最后一行的字母表
    for(i=0; i<26; ++i)
    {
        if(i!=0)
            cout<<" ";
        cout<<(char)('A'+i);
    }


    return 0;
}



#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 103

int main( void )
{
    //str是当前处理的单词， minStr是当前最短的单词
    char str[201], minStr[201];
    //初始化最短单词长度为201
    int minLen=201, len;
    //是否找到了'.'号，即语句结束符
    bool bExit=false;
    //无限循环
    while(true)
    {
        //读入一个单词
        cin>>str;
        //计算单词长度
        len = strlen(str);
        //如果单词最后一个是句号，所以需要特殊处理
        if(str[len-1]=='.')
        {
            //把句号去掉
            str[len-1]='\0';
            //长度减1
            len-=1;
            //设置退出标记
            bExit = true;
        }
        //比较最短单词
        if(len<minLen)
        {
            strcpy(minStr, str);
            minLen = len;
        }
        //找到了句号，退出循环
        if(bExit)
            break;
    }
    cout<<minStr<<endl;
    return 0;
}


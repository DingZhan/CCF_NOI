#include <iostream>
#include <string> //string


using namespace std;


#define MAX_N 256

//largest common sub string
//最长公共子串，以下用的是暴力4层循环方法，会超时，0分
int LCS(const string& a, const string &b)
{
    int maxLen = 0;
    int i, j, k, aLen, bLen;
    bool bSucc;

    aLen = a.length();
    bLen = b.length();

    //初始化最大可能子串长度
    maxLen = min(aLen, bLen);

    //最外层循环是最大子串长度
    while(maxLen>0)
    {
        bSucc=false;
        //第二层循环是字符串a的起点
        for(i=0; i<aLen; ++i)
        {
            //第三层循环是字符串b的起点
            for(j=0; j<bLen; ++j)
            {
                bSucc=true;
                //第四层循环：逐个比较a[i,.., i+maxLen-1], b[i,...,i+maxLen-1]
                for(k=0; k<maxLen; ++k)
                {
                    if(a[(i+k)%aLen]!=b[(j+k)%bLen])
                    {
                        bSucc=false;
                        break;
                    }
                }
                if(bSucc)
                    break;
            }
            if(bSucc)
                break;
        }
        if(bSucc)
            break;
        //没找到，则递减最长公共子串的长度
        --maxLen;
    }
    return maxLen;
}

int main()
{
    string a, b;
    int len;
    while(true)
    {
        cin>>a>>b;
        if(a.length()==1||b.length()==1)
            break;
        len = LCS(a, b);
        cout<<len<<endl;
    }
    return 0;
}

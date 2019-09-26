#include <iostream>
#include <algorithm> //sort
#include <cstring>	//strcmp
using namespace std;

//最多字符串数
#define MAX_N 1001
//字符串最大长度
#define MAX_S 101

struct String
{
    char str[MAX_S]; //字符串
    short id;     //输入序号
    short len;    //字符串长度
    short dictionaryOrder; //字典排序序号
    short keyCount; //关键字出现次数
};

//按字典序降序排列的比较函数
bool CompareByString(const String &a , const String& b)
{
    return strcmp(a.str, b.str)>0;
}

//按输入id升序排列的比较函数
bool CompareByID(const String&a, const String &b)
{
    return a.id<b.id;
}

int main()
{
	//定义字符串结构体数组
    String s[MAX_N];
    int i, j, n, q, L, R, sig, maxLen, id, maxDic;
    char key;
	//取消I/O同步
    std::ios::sync_with_stdio(false);

	//读入字符串总数n和关键字符key
    cin>>n>>key;
	//读入n个字符串
    for(i=0; i<n; ++i)
    {
		//读入字符串
        cin>>s[i].str;
		//初始化该字符串对应数据
        s[i].len=0; //长度初始化为0
        s[i].keyCount =0; //关键字出现次数初始化为0
        s[i].id = i;	//出现顺序id
		//计算字符串长度和key数量
        for(j=0; s[i].str[j]!='\0'; ++j)
        {
            if(s[i].str[j]==key)
                ++s[i].keyCount;
            ++s[i].len;
        }
    }
	//按字典序降序排列字符串
    sort(s, s+n, CompareByString);
	//然后设置字典序的序列值
    for(i=0; i<n; ++i)
        s[i].dictionaryOrder = i;
	//在返回初始输入顺序
    sort(s, s+n, CompareByID);
	
	//读取查询次数q
    cin>>q;
	//计算q次查询
    for(i=0; i<q; ++i)
    {
		//查询区间和查询类型
        cin>>L>>R>>sig;
		//区间是从1开始的，所以要减1
        --L;
        --R;
		//查询区间内最大字符串长度的字符串
        if(sig==0)
        {
            maxLen = 0;
            id = 0;
            for(j=L; j<=R; ++j)
            {
                if(s[j].len>maxLen)
                {
                    id = j;
                    maxLen = s[j].len;
                }
            }
            cout<<s[id].str<<endl;
        }
		//查询区间内的最大字典序
        else if(sig==1)
        {
            maxDic = MAX_N;
            id = 0;
            for(j=L; j<=R; ++j)
            {
                if(s[j].dictionaryOrder<maxDic)
                {
                    id = j;
                    maxDic = s[j].dictionaryOrder;
                }
            }
            cout<<s[id].str<<endl;
        }
		//查询关键字符出现最多的字符串
        else
        {
            maxLen = -1;
            id = 0;
            for(j=L; j<=R; ++j)
            {
                if(s[j].keyCount>maxLen)
                {
                    id = j;
                    maxLen = s[j].keyCount;
                }
            }
            cout<<s[id].str<<endl;
        }
    }
    return 0;
}

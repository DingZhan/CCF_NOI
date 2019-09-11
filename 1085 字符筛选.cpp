#include <iostream>
#include <string> //string


using namespace std;

//0分代码，以为只要出现h,a,p,p,y这些字母至少出现一次或两次(p)即可
bool Bucket(const string& s)
{
    int i;
    int buckets[26]={0};
    for(i=0; i<s.length(); ++i)
    {
        ++buckets[s[i]-'a'];
    }
    if(buckets['h'-'a']>=1 && buckets['a'-'a']>=1
       && buckets['p'-'a']>=2&& buckets['y'-'a']>=1  )
        return true;
    else
        return false;
}
//测试用例happpy, haappy

//状态转移方程
bool State(const string & s)
{
    const char *src = "happy";
    int i, j, srcID=0;
    for(i=0; i<s.length(); ++i)
    {
        if(s[i]==src[srcID])
        {
            ++srcID;
            if(srcID==5)
                return true;
        }
        else
        {
            for(j=0; j<srcID; ++j)
            {
                if(s[i]==src[j])
                {
                    srcID = 0;
                    break;
                }
            }

        }
    }
    return false;
}

int main()
{
    string s;
    cin>>s;
//    if(Bucket(s))
    if(State(s))
        cout<<"Yes！";
    else
        cout<<"No！";
    return 0;
}

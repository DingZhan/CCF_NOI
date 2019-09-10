#include <iostream>
#include <string> //string


using namespace std;


#define MAX_N 256

//largest common sub string
//������Ӵ��������õ��Ǳ���4��ѭ���������ᳬʱ��0��
int LCS(const string& a, const string &b)
{
    int maxLen = 0;
    int i, j, k, aLen, bLen;
    bool bSucc;

    aLen = a.length();
    bLen = b.length();

    //��ʼ���������Ӵ�����
    maxLen = min(aLen, bLen);

    //�����ѭ��������Ӵ�����
    while(maxLen>0)
    {
        bSucc=false;
        //�ڶ���ѭ�����ַ���a�����
        for(i=0; i<aLen; ++i)
        {
            //������ѭ�����ַ���b�����
            for(j=0; j<bLen; ++j)
            {
                bSucc=true;
                //���Ĳ�ѭ��������Ƚ�a[i,.., i+maxLen-1], b[i,...,i+maxLen-1]
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
        //û�ҵ�����ݼ�������Ӵ��ĳ���
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

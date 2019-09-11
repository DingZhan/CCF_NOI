#include <iostream>

using namespace std;

int main ()
{
    string str;
    int i, j;
    //��д��ĸͳ�Ƹ�������26��Ͱ���棬maxNum������ĳ����ĸ���ֵ�������
    short buckets[26] = {0}, maxNum;

    //���������ַ���
    for(i=0; i<4; ++i)
    {
        //����һ���ַ���
        getline(cin, str);
        //��������ַ�
        for(j=0; j<str.size(); ++j)
        {
            //����Ǵ�д��ĸ�������
            if(str[j]>='A' && str[j]<='Z')
                ++buckets[str[j]-'A'];
        }
    }

    //ͳ��ĳ���ַ����ֵ����Ĵ���
    maxNum=0;
    for(i=0; i<26; ++i)
    {
        if(maxNum<buckets[i])
            maxNum = buckets[i];
    }

    //���ѭ����Ӧ����������
    for(i=0; i<maxNum; ++i)
    {
        //�ڲ�ѭ����������ӡ*���߿ո�
        for(j=0; j<26; ++j)
        {
            //��ӡǰ�ÿո�
            if(j!=0)
                cout<<" ";
            //�����ǰ��ĸ�ĸ��������ڼ����������ӡ*�ţ������ӡ�ո�
            //������������ص�����
            if(buckets[j]>=maxNum-i)
                cout<<"*";
            else
                cout<<" ";
        }
        //��ӡһ�еĻس�
        cout<<endl;
    }

    //��ӡ���һ�е���ĸ��
    for(i=0; i<26; ++i)
    {
        if(i!=0)
            cout<<" ";
        cout<<(char)('A'+i);
    }


    return 0;
}



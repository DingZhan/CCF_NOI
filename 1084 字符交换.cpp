#include <iostream>
#include <string> //string
#include <algorithm> //sort

using namespace std;

//���Ƕ������ÿ���ַ���������һ���ڲ��������������С�ַ����ٽ���һ�αȽ�
int main()
{
    int n, i;
    string str, minStr;

    //����n
    cin>>n;
    //����n���ַ���
    for(i=0; i<n; ++i)
    {
        //����һ���ַ���
        cin>>str;
        //���ֵ�����Ը��ַ�����������
        sort(str.begin(), str.end());
        //������ַ���С����С�ַ�����������С�ַ���
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

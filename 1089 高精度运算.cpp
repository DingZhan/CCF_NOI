#include <iostream>
#include <algorithm> //reverse
#include <string> //string

using namespace std;

//定义一个大数类
class BigNum
{
public:
    //默认构造函数
    BigNum(){m_data="0";};
    //带数字字符串的构造函数
    BigNum(const string&v)
    {
        m_data=v;
        //去除高位多余的0
        while(!m_data.empty())
        {
            if(m_data[0]=='0')
                m_data.erase(m_data.begin());
            else
                break;
        }
        if(m_data.empty())
            m_data="0";
    }
public:
    //重载加号
    BigNum operator+(const BigNum & another)
    {
        //这里e是进位，初始进位为0
        int i, j, a, b, e=0;
        string sum;
        //从个位数往高位逐个读取对应位置的数字字符，然后累加
        for(i=(int)m_data.size()-1, j=(int)another.m_data.size()-1;
            i>=0 && j>=0; --i, --j)
        {
            a = m_data[i]-'0';
            b = another.m_data[j]-'0';
            //e是上一次的进位
            e = a+b+e;
            sum.push_back('0'+e%10);
            //得到本次进位
            e = e/10;
        }
        //如果还有一个数字没有读取完成，则继续累加求和
        if(i>=0)
        {
            while(i>=0)
            {
                a = m_data[i]-'0';
                e = a+e;
                sum.push_back('0'+e%10);
                e = e/10;
                --i;
            }
        }
        else if(j>=0)//如果还有一个数字没有读取完成，则继续累加求和
        {
            while(j>=0)
            {
                b = another.m_data[j]-'0';
                e = b+e;
                sum.push_back('0'+e%10);
                e = e/10;
                --j;
            }
        }
        //如果最后还有一个进位，则需要累加
        if(e)
            sum.push_back('0'+e);

        //一定要记得反转字符串
        reverse(sum.begin(), sum.end());
        //构造一个临时类对象传出去
        return BigNum(sum);
    }
    void Print()
    {
        cout<<m_data<<endl;
    }
private:
    string m_data;
};

int main ()
{
    int N, i;
    string a, b;
    cin>>N;
    for(i=0; i<N; ++i)
    {
        cin>>a>>b;
        BigNum aa(a), bb(b), c;
        c = aa+bb;
        c.Print();
    }

    return 0;
}

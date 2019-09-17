#include <iostream>
#include <sstream>  //ostringstream
#include <algorithm> //reverse

using namespace std;



/*溢出代码*/
int OverflowCode(int n)
{
    int i;
    //用int会有溢出问题，unsigned long long也会溢出，因为用对标double代码发现差值很大
    long long f1 = 1, f2 = 1, f3;
    //对标代码，发现unsigned long long也溢出，不得不使用大数类
    double ff1=1, ff2=1, ff3;

    if(n==1)
    {
        cout<<f1<<endl;
        return 0;
    }
    else if(n==2)
    {
        cout<<f2<<endl;
        return 0;
    }
    for(i=3; i<=n; ++i)
    {
        f3 = 3*f2+2*f1;
        f1 = f2;
        f2 = f3;

        ff3 = 3*ff2+2*ff1;
        ff1 = ff2;
        ff2 = ff3;
    }
    cout<<f3<<endl;
    cout<<ff3<<endl;
    return 0;

}

/*只能使用大数类,避免溢出问题*/
class BigData
{
public:
    //默认构造函数，用一个整数值传入
    BigData(int n=0)
    {
        //C里面对应sprintf，将对应数字转换成字符串，这里使用ostringstream类
        ostringstream oss;
        oss<<n;
        //将字符串结果存到成员变量m_data
        m_data = oss.str();
    }
    //重载大数类的+号运算符
    BigData operator + (const BigData & a)
    {
        BigData c;
        int i, j, add=0;
        //这里需要将c里面的0字符先清除掉
        c.m_data.clear();
        //加法的运算规则，add是上一次的进位值
        for(i=(int)m_data.size()-1, j = (int)a.m_data.size()-1; i>=0 && j>=0; --i, --j)
        {
            //转换成数字值的累加
            add = (m_data[i]-'0') + (a.m_data[j]-'0')+add;
            //记得取模，因为add可能大于9
            c.m_data.push_back('0'+add%10);
            //记得获得进位值
            add/=10;
        }
        //如果m_data还有剩余部分没有累加，则继续累加
        while(i>=0)
        {
            add = (m_data[i]-'0')+add;
            c.m_data.push_back('0'+add%10);
            add/=10;
            --i;
        }
        //如果a.m_data还有剩余部分没有累加，则继续累加
        while(j>=0)
        {
            add = (a.m_data[j]-'0')+add;
            //记得取模，因为add可能大于9
            c.m_data.push_back('0'+add%10);
            //记得获得进位值
            add/=10;
            --j;
        }
        //如果还有最后一个进位，则继续累加
        if(add)
            c.m_data.push_back('0'+add);
        //将结果反转，因为我们是把低位先加到字符串中，所以要反转
        std::reverse(c.m_data.begin(), c.m_data.end());
        //返回这个临时的大数类对象c
        return c;
    }

    //digit 介于[0, 9]，所以我们的乘法规则较为简单
    //因为这里只*3和*2
    BigData operator*(int digit)
    {
        BigData c;
        int i, add=0;
        //这里需要将c里面的0字符先清除掉
        c.m_data.clear();
        //乘法的运算规则，add是上一次的进位值
        for(i=(int)m_data.size()-1; i>=0; --i)
        {
            add = (m_data[i]-'0')*digit + add;
            c.m_data.push_back('0'+add%10);
            add/=10;
        }
        //如果还有最后一个进位，则继续累加
        if(add)
            c.m_data.push_back('0'+add);
        //将结果反转，因为我们是把低位先加到字符串中，所以要反转
        std::reverse(c.m_data.begin(), c.m_data.end());
        //返回这个临时的大数类对象c
        return c;
    }
    void Print()
    {
        cout<<m_data;
    }
private:
    string m_data;
} ;
int main()
{
    int n, i;
    cin>>n;
//    OverflowCode(n);
    BigData f1(1), f2(1), f3;
    if(n==1)
    {
        f1.Print();
        cout<<endl;
    }
    else if(n==2)
    {
        f2.Print();
        cout<<endl;
    }
    else
    {
        for(i=3; i<=n; ++i)
        {
            f3 = (f2*3) + (f1*2);
            f1 = f2;
            f2 = f3;
        }
        f3.Print();
        cout<<endl;
    }
    return 0;
}

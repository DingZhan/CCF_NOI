#include <iostream>

using namespace std;

//遍历B进制([2,16]),将p,q,r转换成对应的10进制结果，然后判断十进制结果是否相等

int main( void )
{
    //输入的三个整数
    int p, q, r;
    //将p的每一位数字存储到数组pDigits中，pNum表示p共有多少位
    int pDigits[8], pNum=0;
    //将q的每一位数字存储到数组qDigits中，qNum表示q共有多少位
    int qDigits[8], qNum=0;
    //将r的每一位数字存储到数组rDigits中，rNum表示r共有多少位
    int rDigits[8], rNum=0;
    //B是待求解的进制数，虽然B的取值范围是[2,16],但是循环起始不能从2开始，
    //而是要从max(2, maxDigit+1)开始求解，其中maxDigit是p,q,r每位的最大数字
    int B, maxDigit=0;
    //exp是当前进制位指数
    int exp;
    //pp,qq,rr是当前B进制中,p,q,r转换出来的10进制结果
    int i, pp, qq, rr;

    //读入p, q, r
    cin>>p>>q>>r;

    //将p的每位上的数字存储到数组pDigits中, pNum表示总的位数
    while(p)
    {
        pDigits[pNum] = p%10;
        //刷新最大数值
        if(maxDigit<pDigits[pNum])
            maxDigit = pDigits[pNum];
        p/=10;
        ++pNum;
    }

    //将q的每位上的数字存储到数组qDigits中, qNum表示总的位数
    while(q)
    {
        qDigits[qNum] = q%10;
        //刷新最大数值
        if(maxDigit<qDigits[qNum])
            maxDigit = qDigits[qNum];
        q/=10;
        ++qNum;
    }

    //将r的每位上的数字存储到数组rDigits中, rNum表示总的位数
    while(r)
    {
        rDigits[rNum] = r%10;
        //刷新最大数值
        if(maxDigit<rDigits[rNum])
            maxDigit = rDigits[rNum];
        r/=10;
        ++rNum;
    }

    //遍历进制，将p,q,r转换成对应B进制的十进制数值，然后判断
    //B是待求解的进制数，虽然B的取值范围是[2,16],但是循环起始不能从2开始，
    //而是要从max(2, maxDigit+1)开始求解，其中maxDigit是p,q,r每位的最大数字
    for(B=max(2, maxDigit+1); B<=16; ++B)
    {
        //exp是当前进制位指数,初始为1
        exp=1;
        //p的十进制结果pp
        pp=0;
        for(i=0; i<pNum; ++i)
        {
            pp+=exp*pDigits[i];
            exp*=B;
        }

        exp=1;
        //q的十进制结果qq
        qq=0;
        for(i=0; i<qNum; ++i)
        {
            qq+=exp*qDigits[i];
            exp*=B;
        }

        exp=1;
        //r的十进制结果rr
        rr=0;
        for(i=0; i<rNum; ++i)
        {
            rr+=exp*rDigits[i];
            exp*=B;
        }

        //判断乘法结果是否成立
        if(pp*qq==rr)
            break;
    }

    //不成立
    if(B==17)
        cout<<0<<endl;
    else
        cout<<B<<endl;

    return 0;
}


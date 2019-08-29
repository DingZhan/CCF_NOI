#include <iostream>

using namespace std;

#define MAX_N 101

int main( void )
{
	//为了节省内存，所以用char
    char mat[MAX_N][MAX_N];
    int i, j, id, n, oddRow=0, oddColumn=0, oneNum;
    int lastOddRowID=-1, lastOddColumnID=-1;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        //初始每行1的个数为0
        oneNum = 0;
        for(j=0; j<n; ++j)
        {
            cin>>id;
            mat[i][j] = id;
            if(id==1)
                ++oneNum;
        }
        //如果第i行有奇数个1
        if(oneNum%2)
        {
            //累加奇数行数
            ++oddRow;
            //设置上一个奇数行行号
            lastOddRowID = i;
        }
    }
    //如果奇数行个数超过1，则无论如何都没法一次调整
    if(oddRow>1)
    {
        cout<<"Corrupt\n";
        return 0;
    }

    //开始统计每列1个数的奇数情况
    //j是列号下标
    for(j=0; j<n; ++j)
    {
        //初始每列1的个数为0
        oneNum = 0;
        for(i=0; i<n; ++i)
        {
            if(mat[i][j]==1)
                ++oneNum;
        }
        //如果第j列1的个数为奇数
        if(oneNum%2)
        {
            //累加奇数列数
            ++oddColumn;
            //设置上一个奇数列列号
            lastOddColumnID = j;
        }
    }

    //奇数列和奇数行个数都为0
    if(oddRow==0 && oddColumn==0)
    {
        cout<<"OK\n";
    }
    //奇数行个数为1，而奇数列个数为0，或者奇数行个数为0，而奇数列个数为1，
    //这种情况无论如何都没法一次完成
    else if(oddRow==1 && oddColumn==1)
    {
        cout<<lastOddRowID+1<<" "<<lastOddColumnID+1<<endl;
    }
    //只剩奇数行个数为1，奇数列个数也为1的情况，只要把这个位置的元素反转即可
    else
    {
        cout<<"Corrupt\n";
    }

    return 0;
}


#include <iostream>

using namespace std;

//矩阵对角线元素是<i, i>，另一条对角线元素是<i, n-i-1>

int main()
{
    //读入矩阵
    int mat[4][4], i, j, dia1=0, dia2=0;
    //读入4*4矩阵
    for(i=0; i<4; ++i)
    {
        for(j=0; j<4; ++j)
            cin>>mat[i][j];
    }
    for(i=0; i<4; ++i)
    {
        dia1+=mat[i][i];
        dia2+=mat[i][4-i-1];
    }
    cout<<dia1<<" "<<dia2<<endl;
    return 0;
}


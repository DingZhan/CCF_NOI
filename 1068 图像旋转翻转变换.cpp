#include <iostream>
#include <algorithm> //swap
using namespace std;

#define MAX_N 101

//顺时针旋转90°，旋转矩阵
/* |0   1| |i|=   |i'|
   |-1  0| |j|    |j'|
*/
//行数和列数要交换，所以m, n用引用传递方式
void RotateClockwise(unsigned char image[MAX_N][MAX_N], int& m, int& n)
{
    int i, j;
    char image2[MAX_N][MAX_N];
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
            image2[j][m-i-1] = image[i][j];
    }
    swap(m, n);
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
            image[i][j] = image2[i][j];
    }
}

//逆时针旋转90°，旋转矩阵
/* |0   -1| |i|=   |i'|
   |1    0| |j|    |j'|
*/
//行数和列数要交换，所以m, n用引用传递方式
void RotateCounterClockwise(unsigned char image[MAX_N][MAX_N], int& m, int& n)
{
    int i, j;
    char image2[MAX_N][MAX_N];
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
            image2[n-j-1][i] = image[i][j];
    }
    swap(m, n);
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
            image[i][j] = image2[i][j];
    }
}

//竖直方向镜像：左右反转
void MirrorVertical(unsigned char image[MAX_N][MAX_N], int m, int n)
{
    int i, j, j2;
    for(i=0; i<m; ++i)
    {
        for(j=0, j2=n-1; j<j2; ++j, --j2)
            swap(image[i][j], image[i][j2]);
    }
}

//水平方向镜像：上下反转
void MirrorHorizon(unsigned char image[MAX_N][MAX_N], int m, int n)
{
    int i, i2, j;
    for(i=0, i2=m-1; i<i2; ++i, --i2)
    {
        for(j=0; j<n; ++j)
            swap(image[i][j], image[i2][j]);
    }
}

int main( void )
{
    int m, n, i, j, v;
    unsigned char image[MAX_N][MAX_N];
    string cmd;

    //读入矩阵行数和列数
    cin>>m>>n;
    //读入矩阵，这里灰度图像像素用unsigned char表示，需要借助一个整形中转一下
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            //读入像素值
            cin>>v;
            //装配到矩阵中
            image[i][j] = v;
        }
    }
    //忽略上一个换行
    getline(cin, cmd);
    //得到当前图像编辑命令
    getline(cin, cmd);
    //一个个处理图像编辑命令
    for(i=0; i<cmd.size(); ++i)
    {
        //顺时针旋转
        if(cmd[i]=='A')
            RotateClockwise(image, m , n);
        else if(cmd[i]=='B') //逆时针旋转
            RotateCounterClockwise(image, m , n);
        else if(cmd[i]=='C') //左右反转
            MirrorVertical(image, m , n);
        else if(cmd[i]=='D') //上下反转
            MirrorHorizon(image, m , n);
    }

    //打印最终图像
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(j!=0)
                cout<<" ";
            cout<<(int)image[i][j];
        }
        cout<<endl;
    }

    return 0;
}


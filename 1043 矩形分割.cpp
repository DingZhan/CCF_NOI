#include <iostream>
#include <algorithm>

using namespace std;

//本题使用二分法进行多次面积计算，时间复杂度是O(N*log(R))

/*额外的测试用例
1000
3
1 1 2 1
5 1 2 1
5 2 2 1
答案：6

1000
1
5 1 1 1
答案: 1000
*/

//定义矩形结构体，其中左上角坐标(L,T)，右下角坐标(L+W, T-H)
struct Rect
{
    int L; //左X坐标
    int T; //上Y坐标
    int W; //宽度值
    int H; //高度值
};

//对矩形数组按照左X坐标进行升序排序
//x坐标相同情况下，按照宽度进行升序排序（当然这不是必须的）
bool SortRectByX(const Rect &a, const Rect &b)
{
    //x小的排前面
    if(a.L<b.L)
        return true;
    else if(a.L>b.L) //x大的排后面
        return false;
    else //x相同情况下，按宽度排序，这不是必须的
    {
        if(a.W<b.W)
            return true;
        else if(a.W>b.W)
            return false;
        else
            return true;
    }
}

//最多矩形数目
#define MAX_N 10001

int main()
{
    int R, i, N;
    //用二分法进行多次分割求解，时间复杂度应该是O(N*log(R))
    int low, high, x;
    //上一次有效划分的竖线x坐标，所谓有效划分就是这个x将左边的小矩形划分出的面积和大于右边小矩形的面积和
    int lastValidX=-1;
    //防止求面积时候溢出，所以用long long
    //totalArea是所有小矩形面积总和
    long long totalArea=0, area;
    //矩形数组
    Rect rects[MAX_N];
    //划分矩形时候，竖线是否分割了某个矩形，如果竖线没有分割矩形，则将该线尽量往右挪动，
    //满足“并且，要使得大矩形在直线左边的的面积尽可能大”的要求
    bool bInsideRect, bLastInsideRect;

    //读入大矩形长度
    cin>>R;
    //读入小矩形数目
    cin>>N;
    //读入N个小矩形
    for(i=0; i<N; ++i)
    {
        cin>>rects[i].L>>rects[i].T>>rects[i].W>>rects[i].H;
        //累加小矩形面积
        totalArea+=((long long)rects[i].W)*rects[i].H;
    }
    //对小矩形按X坐标升序进行排序
    sort(rects, rects+N, SortRectByX);

    //二分搜索法，实际上还可以优化成从最左边x，到最右边x+w
    low = 0;
    high = R;
    //中线
    x = (low+high)/2;
    while(low<=high)
    {
        //初始化竖线x的左边矩形面积和
        area = 0;
        //初始化竖线没有从任何矩形中间穿过
        bInsideRect = false;
        for(i=0; i<N; ++i)
        {
            //小矩形完全位于竖线左边，所以累加小矩形全面积
            if(rects[i].L+rects[i].W<=x)
                area+=((long long)rects[i].W)*rects[i].H;
            //小矩形部分位于竖线左边，所以累加小矩形部分面积
            else if(rects[i].L<x && rects[i].L+rects[i].W>x)
            {
                area+=((long long)x-rects[i].L)*rects[i].H;
                //标记竖线从该矩形中间穿过
                bInsideRect = true;
            }
            else //小矩形完全位于竖线右边，因为矩形数组已经按X坐标排序，所以可以放心退出
                break;
        }
        //如果竖线x的左边矩形面积和大于总面积的一半
        if(area>totalArea/2.0)
        {
            //设置区间往左搜索
            high = x-1;
            //设置上次搜索有效坐标和是否穿过多边形标记
            lastValidX = x;
            bLastInsideRect = bInsideRect;
        }
        //左边矩形面积和小于总面积的一半
        else if(area<totalArea/2.0)
        {
            //设置区间往右搜索
            low = x+1;
        }
        else //左边面积等于右边面积，退出搜索
        {
            lastValidX = x;
            bLastInsideRect = bInsideRect;
            break;
        }
        //设置中心，再次搜索
        x = (high+low)/2;
    }
    //如果这样有效的竖线从来没出现过，则把竖线设置在大矩形的最右边
    if(lastValidX==-1)
    {
        x = R;
        bInsideRect = false;
    }
    else
    {
        //把竖线设置回最后一次有效的竖线位置
        x = lastValidX;
        //把竖线穿过矩形标记设置回最后一次有效地穿过矩形标记
        bInsideRect = bLastInsideRect;
    }
    //如果竖线x没有穿过任何矩形，则把它尽量往右挪动直到碰到下一个矩形地左边
    if(!bInsideRect)
    {
        for(i=0; i<N; ++i)
        {
            //向右碰到了第一个矩形
            if(rects[i].L>x)
            {
                x = rects[i].L;
                break;
            }
        }
        //如果没有碰到任何矩形地左边，则干脆挪到大矩形地右边
        //满足“并且，要使得大矩形在直线左边的的面积尽可能大”的要求
        if(i==N)
            x = R;
    }
    cout<<x<<endl;
    return 0;
}

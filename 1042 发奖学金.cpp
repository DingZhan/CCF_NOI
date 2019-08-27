#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
    short id;   //报名号
    int chinese;//语文成绩
    int math;   //数学成绩
    int english;//英语成绩
    int total;  //总成绩
};

//总成绩降序排列
bool SortByScoreDescent(const Student& a, const Student&b)
{
	//总成绩高的排前面
    if(a.total>b.total)
        return true;
    else if(a.total<b.total) //总成绩低的排后面
        return false;
    else //总成绩相同的情况下
    {
		//语文成绩高的排前面
        if(a.chinese>b.chinese)
            return true;
        else if(a.chinese<b.chinese) //语文成绩低的排后面
            return false;
        else //语文成绩也相同的情况下，学号小的排前面
            return a.id<b.id;
    }
}

//最多人数
#define MAX_N 5001
int main()
{
    int n, i;
    //学生数组
    Student students[MAX_N];
    //总人数
    cin>>n;
    //读入n个志愿者编号和笔试成绩
    for(i=0; i<n; ++i)
    {
        students[i].id = i+1;
        cin>>students[i].chinese>>students[i].math>>students[i].english;
        students[i].total = students[i].chinese+students[i].math+students[i].english;
    }
    //按成绩降序排列
    sort(students, students+n, SortByScoreDescent);

    for(i=0; i<5; ++i)
        cout<<students[i].id<<" "<<students[i].total<<endl;
    return 0;
}

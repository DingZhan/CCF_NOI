#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    long long a, n, last;

    while(cin>>a>>n)
    {
        priority_queue<int, vector<int>, greater<int> > nums;

        nums.push(a);
        last = a-1;
        while(n>0)
        {
            a = nums.top();
            if(a!=last)
                --n;
            nums.pop();
            if(a==last)
                continue;
            last = a;
            nums.push(2*a+1);
            nums.push(3*a+1);
        }
        cout<<a<<endl;
    }

    return 0;
}

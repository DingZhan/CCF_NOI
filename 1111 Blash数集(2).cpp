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
        set<long long> nums;
        set<long long>::iterator iter;

        nums.insert(a);
        iter = nums.begin();
        while(nums.size()<=2*n)
        {
            a = *iter;
            nums.insert(2*a+1);
            nums.insert(3*a+1);
            ++iter;
        }
        for(iter=nums.begin(); iter!=nums.end() && n>0; ++iter)
        {
            a = *iter;
//            cout<<a<<endl;
            --n;
        }
        cout<<a<<endl;
    }

    return 0;
}

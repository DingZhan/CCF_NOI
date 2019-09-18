#include <iostream>

using namespace std;

int main()
{
    int m, i, k, j, t;
    string a, op, b;
    
    cin>>m;
    //读入m个问题
    for(i=0; i<m; ++i)
    {
        //k个名字
        cin>>k;
        //先读入一个名字
        cin>>a;
        //桶排序：把名字中所有字母设置到对应的桶里面
        bool buckets[26]={false};
        for(t=0; t<a.size(); ++t)
            buckets[a[t]-'a'] = true;
        //读入剩下的k-1个名字
        for(j=1; j<k; ++j)
        {
            //读入操作符
            cin>>op;
            //读入另一个名字
            cin>>b;
            //并集
            if(op=="+")
            {
                for(t=0; t<b.size(); ++t)
                    buckets[b[t]-'a'] = true;
            }
            //交集
            else if(op=="*")
            {
                //用另一个桶，装右边的名字中的字符
                bool buckets2[26]={false};
                for(t=0; t<b.size(); ++t)
                    buckets2[b[t]-'a'] = true;
                //两个桶的交集
                for(t=0; t<26; ++t)
                    buckets[t] = (buckets[t] && buckets2[t]);
            }
            //差集
            else if(op=="-")
            {
                for(t=0; t<b.size(); ++t)
                    buckets[b[t]-'a'] = false;
            }
        }
        //打印结果
        for(j=0; j<26; ++j)
        {
            if(buckets[j])
                cout<<char('a'+j);
        }
        cout<<endl;
    }


    return 0;
}

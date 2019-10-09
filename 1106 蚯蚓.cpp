#include <iostream>
#include <list>

using namespace std;

#define MAX_N 20001
#define MAX_M 20001

int main()
{
    int i, j, n, m, a, b, c, myb, myc;
    list<int> lens;
    list<int>::iterator itb, itc;

    cin>>n>>m;
    for(i=0; i<n; ++i)
    {
        cin>>a;
        lens.insert(lens.front(), a);
    }

    cin>>m;
    for(i=0; i<m; ++i)
    {
        cin>>a;
        if(a==0)
        {
            cin>>myb>>myc;
            itb = lens.begin();
            itc = lens.begin();
            while(myb>=0 || myb>=0)
            {
                if(myb>=0)
                {
                    ++itb;
                    if(itb==lens.end())
                        itb = lens.front();
                    --myb;
                }
                if(myc>=0)
                {
                    ++itc;
                    if(itc==lens.end())
                        itc = lens.front();
                    --myc;
                }
            }
        }
        else if(a==1)
        {
            cin>>b;
            if(b<=*itb)
            {
                cout<<"error!"<<endl;
            }
            else
            {
                c = *itb - b;
                *itb = b;
                ++itb;
                lens.insert(itb, c);
            }
        }
        else if(a==2)
        {
            cin>>b;
            if(b<=*itb)
            {

            }
            else
            {
                c = *itb - b;
                *itb = b;
                ++itb;
                lens.insert(itb, c);
            }

        }
        else if(a==3)
        {
            swap(itb, itc);
        }
        else if(a==4)
        {
            (*itc)--;
            lens.insert(itc+1, 1);
        }
        else if(a==5)
        {
            cout<<*itb;
        }
    }



}

#include <iostream>

using namespace std;

//Ñ§»áÓÃisalpha, isdigit

int main ()
{
    string str;
    bool bSucc=true;
    int i;

    cin>>str;

    if(!isalpha(str[0]) && str[0]!='_')
        bSucc=false;
    else
    {
        for(i=0; i<str.size(); ++i)
        {
            if(!isalpha(str[i]) && !isdigit(str[i]) && str[i]!='_')
            {
                bSucc=false;
                break;
            }
        }
    }
    if(bSucc)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}



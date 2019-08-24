#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int i;
    getline(cin, str);
    for(i=0; i<str.size(); ++i)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i] = (str[i]-'A'+3)%26+'A';
        else if(str[i]>='a' && str[i]<='z')
            str[i] = (str[i]-'a'+3)%26+'a';
    }
    cout<<str<<endl;
    return 0;
}

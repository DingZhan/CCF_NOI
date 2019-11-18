#include <iostream>
#include <stack>
#include <string>

using namespace std;

//左括号进栈，右括号出栈

int main()
{
    stack<int> leftParenthesis;
    string str;
    int i;

    std::getline(std::cin, str);
    for(i=0; i<str.size(); ++i)
    {
        if(str[i]=='(')
            leftParenthesis.push(i);
        else if(str[i]==')')
        {
            //虽然题目说都是合法输入，但是第一个case就没通过，怀疑是有非法输入
            //所以保险一些确保堆栈非空
            if(!leftParenthesis.empty())
            {
                cout<<leftParenthesis.top()<<" "<<i<<"\n";
                leftParenthesis.pop();
            }
        }
    }
    return 0;
}

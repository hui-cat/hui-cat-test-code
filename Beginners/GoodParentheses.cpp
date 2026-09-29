#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string str;
    cin >> n;
    while(n--)
    {
        cin >> str;
        stack<char> stk;
        bool isGood=true;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '(')
            {
                stk.push('(');
            }
            if (str[j] == '[')
            {
                stk.push('[');
            }
            if (str[j] == ')')
            {
                if (!stk.empty())
                {
                    if (stk.top() == '(')
                    {
                        stk.pop();
                        continue;
                    }
                }
                isGood=false;
                break;
            }
            if (str[j] == ']')
            {
                if (!stk.empty())
                {
                    if (stk.top() == '[')
                    {
                        stk.pop();
                        continue;
                    }
                }
                isGood=false;
                break;
            }
        }
        if (isGood && stk.empty() && stk.empty())
        {
            cout << "Yes" << endl;
        } else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
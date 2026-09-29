#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str.empty())
        {
            continue;
        }
        stack<int> stk;
        string mark(str.size(), ' ');
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                stk.push(i);
            } else if (str[i] == ')')
            {
                if (stk.empty())
                {
                    mark[i] = '?';
                    continue;
                }
                stk.pop();
            } 
        }
        while (!stk.empty()) 
        {
            mark[stk.top()] = '$';
            stk.pop();
        }
        cout << str << endl;
        cout << mark << endl;
    }
    return 0;
}
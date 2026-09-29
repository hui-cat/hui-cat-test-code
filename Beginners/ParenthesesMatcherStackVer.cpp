#include <bits/stdc++.h>
using namespace std;

struct StringMatcher
{
    string str;
    vector<bool> isMatch;
};

void ParenthesesMatcher(StringMatcher& strInput)
{
    stack<int> stk;
    for (int i = 0; i < strInput.str.size(); i++)
    {
        if (strInput.str[i] == '(')
        {
            stk.push(i);
        }
        else if (strInput.str[i] == ')')
        {
            if (!stk.empty())
            {
                strInput.isMatch[i]=true;
                strInput.isMatch[stk.top()]=true;
                stk.pop();
            }
        } else
        {
            strInput.isMatch[i]=true;
        }
    }
}

void ResultOutput(StringMatcher strInput)
{
    for (int i = 0; i < strInput.str.size(); i++)
    {
        if (!strInput.isMatch[i])
        {
            if (strInput.str[i] == '(')
            {
                cout << '$';
            } else if (strInput.str[i] == ')')
            {
                cout << '?';
            }
            continue;
        }
        cout << ' ';
    }
    cout << endl;
}

int main()
{
    string input;
    vector<StringMatcher> strings;
    while (getline(cin, input))
    {
        StringMatcher temp;
        temp.str=input;
        temp.isMatch.resize(input.size());
        strings.push_back(temp);
    }
    for (size_t i = 0; i < strings.size(); i++)
    {
        ParenthesesMatcher(strings[i]);
    }
    for (size_t i = 0; i < strings.size(); i++)
    {
        cout << strings[i].str << endl;
        ResultOutput(strings[i]);
    }
    return 0;
}
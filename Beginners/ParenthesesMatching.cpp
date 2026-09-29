#include <bits/stdc++.h>
using namespace std;
struct StringMatcher
{
    string str;
    vector<bool> isMatch;
};

void ParenthesesMatcher(int index, StringMatcher & strInput)
{
    for (size_t i = index; i < strInput.str.size(); i++)
    {
        if (strInput.isMatch[i])
        {
            continue;
        }
        
        if (strInput.str[i] == '(')
        {
            ParenthesesMatcher(i+1, strInput);
        } else if (strInput.str[i] == ')')
        {
            if (index==0)
            {
                continue;
            }
            if (strInput.str[index-1] == '(')
            {
                strInput.isMatch[i]=true;
                strInput.isMatch[index-1]=true;
                return;
            }
            continue;
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
    while(getline(cin, input))
    {
        StringMatcher temp;
        temp.str = input;
        temp.isMatch.resize(input.size(), false);
        strings.push_back(temp);
    }
    for (int i = 0; i < strings.size(); i++)
    {
        ParenthesesMatcher(0,strings[i]);
    }
    for (int i = 0; i < strings.size(); i++)
    {
        cout << strings[i].str << endl;
        ResultOutput(strings[i]);
    }
    return 0;
}
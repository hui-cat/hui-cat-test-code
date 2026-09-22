#include <bits/stdc++.h>
using namespace std;

string LargeSum(string a, string b)
{
    bool oneMore = false;
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.size() >= b.size())
    {
        b.resize(a.size(), '0');
    } else 
    {
        a.resize(b.size(), '0');
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        
        int digit = a[i] + b[i] - '0' - '0' + oneMore;
        oneMore = false;
        if (digit>=10)
        {
            digit-=10;
            oneMore = true;
        }
            ans.push_back('0' + digit);
    }
    if (oneMore)
    {
        ans.push_back('1');
    }
    while (ans.size() > 1 && ans.back() == '0') 
    {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a,b,ans;
    vector<string> parts;
    cin >> a >> b;
    for (int i = b.size()-1; i >= 0; i--)
    {
        string part=a;
        for (size_t j = 1; j < b[i] - '0'; j++)
        {
            part = LargeSum(part, a);
        }
        if (b[i] == '0') 
        {
            part='0';
            }
        for (int j = 0; j < b.size()-1-i; j++)
        {
            part.push_back('0');
        }
        parts.push_back(part);
    }
    ans = parts[0];
    for (auto it = parts.begin() + 1; it < parts.end(); it++)
    {
        ans = LargeSum(ans, *it);
    }
    while (ans.size() > 1 && ans[0] == '0') 
    {
        ans.erase(ans.begin());
    }
    cout << ans << endl;
    return 0;
}
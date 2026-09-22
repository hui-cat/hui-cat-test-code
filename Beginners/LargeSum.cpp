#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b,ans;
    bool oneMore=false;
    cin >> a >> b;
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
    for (int i = ans.size()-1; i >= 0; i--)
    {
        if (ans[i] == '0') ans.erase(i);
        else break;
    }
    if (oneMore)
    {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
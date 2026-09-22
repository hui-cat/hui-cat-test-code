#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b,ans;
    bool oneLess=false, isMinus = false;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '0') a.erase(i);
        else break;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '0') b.erase(i);
        else break;
    }
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
        
        int digit = a[i] - b[i] - oneLess;
        oneLess = false;
        if (digit<0)
        {
            digit+=10;
            oneLess = true;
        }
        ans.push_back('0' + digit);
    }
    if (oneLess)
    {
        ans.clear();
        oneLess = false;
        isMinus = true;
        for (size_t i = 0; i < a.size(); i++)
        {
            int digit = b[i] - a[i] - oneLess;
            oneLess = false;
            if (digit<0)
            {
                digit+=10;
                oneLess = true;
            }
            ans.push_back('0' + digit);
        }
    }
    for (int i = ans.size()-1; i >= 0; i--)
    {
        if (ans[i] == '0') ans.erase(i);
        else break;
    }
    if (isMinus)
    {
        ans.push_back('-');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
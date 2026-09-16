#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,ans;
    getline(cin, s);
    for (auto &&i : s)
    {
        switch (i)
        {
        case 'A':
            ans.append("T");
            break;
        case 'G':
            ans.append("C");
            break;
        case 'T':
            ans.append("A");
            break;
        case 'C':
            ans.append("G");
            break;
        default:
            break;
        }
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        string r(s.rbegin(), s.rend());
        if (s==r)
        {
            cout << "yes";
        } else
        {
            cout << "no";
        }
    }
    return 0;
}
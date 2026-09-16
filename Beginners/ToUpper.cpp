#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for (auto &&i : s)
    {
        if (islower(i))
        {
            i=toupper(i);
        }
    }
    cout << s;
    return 0;
}
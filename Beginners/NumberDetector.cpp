#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int t=0;
    getline(cin, s);
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            t++;
        }
    }
    cout << t;
    return 0;
}
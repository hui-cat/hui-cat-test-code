#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    for (size_t i = 2; i < 100000; i++)
    {
        if (a%i==b%i && a%i==c%i)
        {
            cout << i;
            break;
        }
    }
    return 0;
}
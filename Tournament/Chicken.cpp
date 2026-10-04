#include <bits/stdc++.h>
using namespace std;
int main()
{
    int money,n=0;
    cin >>money;
    while (1)
    {
        if (money >= 6)
        {
            money-=6;
            n++;
        } else break;
        if (money>=4)
        {
            money-=4;
            n++;
        } else break;
    }
    cout << n;
    return 0;
}
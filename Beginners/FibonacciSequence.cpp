#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a=1,b=1,c=0,t;
    cin >> t;
    for (int i = 3; i <= t; i++)
    {
        if (t==1 || t==2)
        {
            c=1;
            break;
        }
        c=a+b;
        a=b; b=c;
    }
    cout << c << endl;
    return 0;
}
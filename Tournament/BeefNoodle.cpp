#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    if (a+d <= b+c && a+d <= e)
    {
        cout << a+d;
    } else if (b+c <= a+d && b+c <= e)
    {
        cout << b+c;
    } else
    {
        cout << e;
    }
    return 0;
}
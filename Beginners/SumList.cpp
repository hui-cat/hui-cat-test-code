#include <bits/stdc++.h>
using namespace std;

int Calc(int n)
{
    if (n==1)
    {
        return 0;
    } 
    if (n==2)
    {
        return 1;
    }
    return Calc(n-1)+Calc(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout << Calc(n);
    return 0;
}
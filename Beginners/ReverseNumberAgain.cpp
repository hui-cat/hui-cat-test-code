#include <bits/stdc++.h>
using namespace std;

long long ans=0;

void getReverse(long long n)
{
    if (!n)
    {
        return;
    }
    ans = ans*10 + n%10;
    getReverse(n/10);
}

int main()
{
    long long input;
    cin >> input;
    getReverse(input);
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long fastPow(long long a, long long b, long long p);
int main()
{
    long long a,b,p;
    cin >> a >> b >> p;
    int s = fastPow(a,b,p);
    cout << a << "^" << b << " mod " << p << "=" << s << endl;
    return 0;
}

long long fastPow(long long a, long long b, long long p)
{
    long long ans = 1;
    a%=p;
    while (b!=0)
    {
        if (b & 1)
        {
            ans = (ans * a) % p;
        }
        a = (a * a) % p;
        b>>=1;
    }
    return ans;
}
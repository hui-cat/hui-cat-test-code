#include <bits/stdc++.h>
using namespace std;

long long getGCD(long long a, long long b)
{
    if (b==0) return a;
    return getGCD(b, a % b);
}

int main()
{
    long long a,b;
    cin >> a >> b;
    cout << "gcd=" << getGCD(a, b) << endl;
    return 0;
}
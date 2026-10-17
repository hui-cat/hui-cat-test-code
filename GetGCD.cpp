#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    cin >> a;
    cin >> b;
    vector<long long> commonCD;
    bool isFinish=false;
    while (1)
    {
        long long c=2;
        while (!(a%c==0) || !(b%c==0))
        {
            if (c>a || c>b)
            {
                isFinish=true;
                break;
            }
            c++;
        }
        if (isFinish) break;
        a/=c;
        b/=c;
        commonCD.push_back(c);
    }
    long long result =1;
    for (auto &&i : commonCD)
    {
        result *= i;
    }
    cout << "gcd=" << result;
    return 0;
}
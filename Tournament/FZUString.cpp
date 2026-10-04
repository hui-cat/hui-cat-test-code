#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long ans =0;
    long long pow3 =1;
    for (int i = 1; i <= n; i++)
    {
        if (pow3 <= n)
        {
            pow3*=3;
        }
        if (pow3>n-i+1)
        {
            ans += (n-i+1);
        } else
        {
            ans += pow3;
        }
    }
    cout << ans;
    return 0; 
}
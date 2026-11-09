#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long capacity, itemTotal;
    cin >> capacity >> itemTotal;
    vector<long long> weight(itemTotal+1);
    vector<long long> value(itemTotal+1);
    vector<long long> dp(capacity+1, 0);
    for (long long k = 1; k <= itemTotal; k++)
    {
        cin >> weight[k] >> value[k];
    }
    for (long long i = 1; i <= itemTotal; i++)
    {
        for (long long j = weight[i]; j <= capacity; j++)
        {
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    cout << dp[capacity] << endl;
    return 0;
}
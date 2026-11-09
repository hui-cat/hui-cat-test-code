#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int capacity, itemTotal;
    cin >> capacity >> itemTotal;
    vector<int> weight(itemTotal+1);
    vector<int> value(itemTotal+1);
    vector<int> dp(capacity+1, 0);
    for (int k = 1; k <= itemTotal; k++)
    {
        cin >> weight[k] >> value[k];
    }
    for (int i = 1; i <= itemTotal; i++)
    {
        for (int j = capacity; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    cout << dp[capacity] << endl;
    return 0;
}
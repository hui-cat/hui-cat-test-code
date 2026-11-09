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
    vector<vector<int>> dp(itemTotal+1, vector<int>(capacity+1, 0));
    for (int k = 1; k <= itemTotal; k++)
    {
        cin >> weight[k] >> value[k];
    }
    for (int i = 1; i <= itemTotal; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j<weight[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }
        }
    }
    cout << dp[itemTotal][capacity] << endl;
    return 0;
}
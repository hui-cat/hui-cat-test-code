#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> sum(n+1, 0);
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n-len+1; i++)
        {
            int j=i+len-1;
            dp[i][j] = 1e9;
            for (int k = i; k < j; k++)
            {
                int current_cost = sum[j] - sum[i-1];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + current_cost);
            }
            
        }
        
    }
    cout << dp[1][n] << endl;
    return 0;
}
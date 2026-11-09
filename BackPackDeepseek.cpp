#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int w[MAXN], v[MAXN];
int dp[MAXN][MAXN]; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int capacity, itemTotal;
    
    while (cin >> capacity >> itemTotal) 
    {
        // 3. 每次循环清空 dp 数组（非常关键）
        for (int i = 0; i <= itemTotal; i++) {
            for (int j = 0; j <= capacity; j++) {
                dp[i][j] = 0;
            }
        }

        for (int k = 1; k <= itemTotal; k++)
        {
            cin >> w[k] >> v[k];
        }
        
        for (int i = 1; i <= itemTotal; i++)
        {
            for (int j = 1; j <= capacity; j++)
            {
                if (j < w[i])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + v[i]);
                }
            }
        }
        cout << dp[itemTotal][capacity] << "\n";
    }
    return 0;
}
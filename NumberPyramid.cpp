#include <bits/stdc++.h>
using namespace std;
int prs[2001][2001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> prs[i][j];
        }
        if (i==0)
        {
            continue;
        }
        for (int j = 0; j <= i; j++)
        {
            int k=0, l=0, m=0;
            if (j-1>=0) k=prs[i-1][j-1];
            if (j<i) m=prs[i-1][j];

            prs[i][j] += max(k, m); 
        }
        
    }
    cout << *max_element(begin(prs[n-1]), end(prs[n-1]));
    return 0;
}
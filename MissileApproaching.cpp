#include <bits/stdc++.h>
using namespace std;
int missile[1001], dp1[1001], dp2[1001];
int main()
{
    fill(begin(dp1), end(dp1), 1);
    fill(begin(dp2), end(dp2), 1);
    int n=0, temp;
    while (cin >> temp)
    {
        missile[n] = temp;
        n++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (missile[j] >= missile[i])
            {
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }
    cout << *max_element(begin(dp1), end(dp1)) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (missile[j] < missile[i])
            {
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }
    cout << *max_element(begin(dp2), end(dp2)) << endl;
    return 0;
}
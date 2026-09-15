#include <bits/stdc++.h>
using namespace std;
bool lights[5000];
int main()
{
    int n,m;
    cin >> n >> m;
    for (size_t i = 2; i <= m; i++)
    {
        for (size_t j = 1; j*i <= n; j++)
        {
            lights[j*i-1] = !lights[j*i-1];
        }
    }
    vector<int> lightsOut;
    for (size_t i = 0; i < n; i++)
    {
        if (!lights[i])
        {
            lightsOut.push_back(i+1);
        }
    }
    for (int i : lightsOut)
    {
        if (i==lightsOut.back())
        {
            cout << i;
            break;
        }
        cout << i << ",";
    }
    return 0;
}
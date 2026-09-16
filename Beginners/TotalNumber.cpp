#include <bits/stdc++.h>
using namespace std;

bool isWholeNum(int n)
{
    vector<int> factors;
    int s=0;
    for (int i = 1; i < n; i++)
    {
        if (n%i==0)
        {
            factors.push_back(i);
        }
    }
    for(int i : factors)
    {
        s+=i;
    }
    if (s==n)
    {
        return true;
    } else
    {
        return false;
    }
}

int main()
{
    int m;
    cin >> m;
    for (size_t i = 2; i < m; i++)
    {
        if (isWholeNum(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int digit(int n, int k)
{
    for (size_t i = 1; i < k; i++)
    {
        n/=10;
    }
    return n%10;
}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << digit(n, k);
    return 0;
}
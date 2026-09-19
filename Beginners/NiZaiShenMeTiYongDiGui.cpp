#include <bits/stdc++.h>
using namespace std;
int SumUpTo(int n)
{
    if (n==0)
    {
        return 0;
    }
    int sum=SumUpTo(n-1);
    return (sum+n);
}

int main()
{
    int N;
    cin >> N;
    cout << SumUpTo(N);
    return 0;
}
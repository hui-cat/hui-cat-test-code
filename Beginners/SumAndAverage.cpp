#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum+=a;
    }
    double average;
    average = (double)sum/(double)n;
    cout << sum << " " << fixed << setprecision(5) << average;
}
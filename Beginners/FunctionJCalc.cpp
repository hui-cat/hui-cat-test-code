#include <bits/stdc++.h>
using namespace std;

double Function(double x, int n)
{
    double result=sqrt(1.0+x);
    for (size_t i = 2; i <= n; i++)
    {
        result = sqrt(result+i);
    }
    return result;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << fixed << setprecision(2) << Function(x,n);
    return 0;
}
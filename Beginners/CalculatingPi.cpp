#include <bits/stdc++.h>
using namespace std;
double arctan(double x)
{
    int ind=1, n=1;
    double result=0.0;
    while (1)
    {
        double next=(pow(x,n)/n);
        if (next<1E-6)
        {
            return result;
        }
        result+=ind * next;
        ind=(-ind);
        n+=2;
    }
}

int main()
{
    double pi = 6 * arctan((1.0/sqrt(3)));
    cout << fixed << setprecision(10) << pi;
    return 0;
}
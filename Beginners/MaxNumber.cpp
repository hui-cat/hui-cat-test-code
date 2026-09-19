#include <bits/stdc++.h>
using namespace std;
int max(int a, int b, int c)
{
    int nums[3] = {a,b,c};
    int m=0;
    for(int i : nums)
    {
        if (i>m)
        {
            m=i;
        }
    }
    return m;
}

int main()
{
    double m=0.0;
    int a,b,c;
    cin >> a >> b >> c;
    if (max(a+b,b,c) * max(a,b,b+c))
    {
        m=(double)max(a,b,c)/(max(a+b,b,c) * max(a,b,b+c));
    }
    cout << fixed << setprecision(3) << m;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double s=1;
    int n,i=1;
    cin >> n;
    while (s<=n)
    {
        i++;
        s+=1.0/i;
    }
    cout << i;
}
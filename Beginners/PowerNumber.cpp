#include <bits/stdc++.h>
using namespace std;
int main()
{
    long a,n;
    cin >> a >> n;
    long temp=a;
    for (int i = 0; i < n-1; i++)
    {
        a*=temp;
    }
    cout << a;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a,b;
    cin >> a >> b;
    double rate=b/a*100;
    cout << fixed << setprecision(3) << rate << "%";
    return 0;
}
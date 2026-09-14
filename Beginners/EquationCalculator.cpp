#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    double delta = b*b - 4*a*c;
    cout << fixed << setprecision(5);
    if (delta < 0)
    {
        cout << "No answer!";
    } else if (delta == 0)
    {
        cout << "x1=x2=" << (-b)/(2*a);
    } else
    {
        double root1 = ((-b)+sqrt(delta))/(2*a), root2 = ((-b)-sqrt(delta))/(2*a);
        if (root1 > root2)
        {
            cout << "x1=" << root2 << ";x2=" << root1;
        } else{
            cout << "x1=" << root1 << ";x2=" << root2;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
const long long max_var = 998244353;
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        long long n,x,a,p=0,r=1;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if ((x % max_var) * ((p+a) % max_var) % max_var >= ((x+a) % max_var) * (p % max_var) % max_var)
            {
                r = ((x+a) % max_var) * (p % max_var) % max_var;
                x+=a;
            } else
            {
                r= (x % max_var) * ((p+a) % max_var) % max_var;
                p+=a;
            }
        }
        cout << r << endl;
    }
    return 0;
}
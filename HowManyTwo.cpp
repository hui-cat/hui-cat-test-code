#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L,r,s=0;
    cin >> L;
    cin >> r;
    for (int i = L; i <= r; i++)
    {
        while (i)
        {
            if (i%10==2)
            {
                s++;
            }
            i/=10;
        }
    }
    cout << s;
    return 0;
}

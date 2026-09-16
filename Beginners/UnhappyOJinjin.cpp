#include <bits/stdc++.h>
using namespace std;
int main()
{
    int hours[7]={0};
    int a,b;
    for (size_t i = 0; i < 7; i++)
    {
        cin >> a >> b;
        hours[i] = a+b;
    }
    int mH=0,mI=0;
    for (size_t i = 0; i < 7; i++)
    {
        if (hours[i]>mH)
        {
            mH=hours[i];
            mI=i;
        }
    }
    
    if (mH>=8)
    {
        cout << (mI+1);
    } else
    {
        cout << "0";
    }
    return 0;
}
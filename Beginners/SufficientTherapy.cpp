#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a,b;
    double rates[30];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        rates[i]=((double)b/(double)a);
    }
    for (int i = 1; i < n; i++)
    {
        if (rates[i]-rates[0]>0.05)
        {
            cout << "better" << endl;
        } else if (rates[i]-rates[0]<-0.05)
        {
            cout << "worse" << endl;
        } else {
            cout << "same" << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

void outMax(int max)
{
    int a=1,b=1,c=1;
    for (int i = 2; i < max; i++)
    {
        c=a+b;
        if (c>=1000)
        {
            c-=1000;
        }
        a=b; b=c;
    }
    cout << c << endl;
}

int main()
{
    int max;
    cin >> max;
    vector<int> indexes(max);
    for (int i = 0; i < indexes.size(); i++)
    {
        cin >> indexes[i];
    }
    for (auto it = indexes.begin(); it != indexes.end(); ++it)
    {
        outMax(*it);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool WinCheck(int greater, int lesser, bool isFirst)
{
    if (greater % lesser == 0)
    {
        return isFirst;
    }
    else if(greater / lesser>=2)
    {
        return isFirst;
    }
    else
    {
        return WinCheck(lesser, greater-lesser, !isFirst);
    }
}

int main()
{
    int a,b;
    while (1)
    {
        cin >> a >> b;
        bool isWin=false;
        if(a==0 || b==0) break;
        if (a/b >= 2)
        {
            cout << "win" << endl;
        } 
        else
        {
            if (a>b)
            {
                isWin = WinCheck(a, b, true);
            }
            else
            {
                isWin = WinCheck(b, a, true);
            }
            if (isWin) cout << "win" << endl;
            else cout << "lose" << endl;
        }
    }
    return 0;
}
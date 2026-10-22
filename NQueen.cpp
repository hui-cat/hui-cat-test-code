#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
int pos[15];
bool dia1[30], dia2[30], col[15];

void v_search_queen(int currentQueen)
{
    if (currentQueen==n)
    {
        ans++;
        if(ans<=3)
        {
            for (int i = 0; i < n; i++)
            {
                cout << pos[i]+1 << (i == n-1 ? "" : " ");
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(!col[i] && !dia1[currentQueen-i+15] && !dia2[currentQueen+i])
        {
            col[i] = true;
            dia1[currentQueen-i+15] = true;
            dia2[currentQueen+i] = true;
            pos[currentQueen] = i;
            v_search_queen(currentQueen+1);
            col[i] = false;
            dia1[currentQueen-i+15] = false;
            dia2[currentQueen+i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    v_search_queen(0);
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool bfs(int current, int max, int pos, int tgt, int action)
{
    if(action == 0)
    {
        pos += 1;
    }
    else if (action == 1)
    {
        pos -= 1;
    }
    else
    {
        pos *= 2;
    }

    if (pos == tgt) return true;

    if (current < max)
    {
        return bfs(current+1, max, pos, tgt, 0) | bfs(current+1, max, pos, tgt, 1) | bfs(current+1, max, pos, tgt, 2);
    }
    else
    {
        return false;
    }
}

int main()
{
    int pos,tgt;
    cin >> pos >> tgt;
    int i=0;
    while (!(bfs(0, i, pos, tgt, 0) | bfs(0, i, pos, tgt, 1) | bfs(0, 1, pos, tgt, 2)))
    {
        i++;
    }
    cout << i+1 << endl;
    return 0;
}
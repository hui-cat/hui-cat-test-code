#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int main()
{
    int walked[MAXN];
    fill(begin(walked), end(walked), -1);
    int n,k;
    cin >> n >> k;

    if (n>=k)
    {
        cout << n-k << endl;
        return 0;
    }

    queue<int> q;
    q.push(n);
    walked[n]=0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == k)
        {
            cout << walked[current] << endl;
            return 0;
        }

        int nextPos[3] = {current + 1, current - 1, current * 2};
        for (int i = 0; i < 3; i++)
        {
            if (i==2 && current > k) continue;

            if (nextPos[i]>=0 && nextPos[i] < MAXN && walked[nextPos[i]] == -1)
            {
                q.push(nextPos[i]);
                walked[nextPos[i]] = walked[current]+1;
            }
        }
        
    }
    
}
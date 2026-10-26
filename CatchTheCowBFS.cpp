#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int, int> Walked;
    queue<int> q;
    int n,k;
    cin >> n >> k;
    
    if (n>=k)
    {
        cout << n-k << endl;
        return 0;
    }

    q.push(n);
    Walked.insert({n,0});

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == k)
        {
            cout << Walked[current] << endl;
            return 0;
        }

        int nextPos[3] = {current + 1, current - 1, current * 2};
        for (int i = 0; i < 3; i++)
        {
            if (nextPos[i] >= 0 && nextPos[i] <= 100005 && Walked.find(nextPos[i]) == Walked.end())
            {
                q.push(nextPos[i]);
                Walked.insert({nextPos[i], Walked[current]+1});
            }
        }
        
    }
    
}
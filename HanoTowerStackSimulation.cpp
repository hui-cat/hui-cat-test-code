#include <bits/stdc++.h>
using namespace std;

struct Task
{
    int n;
    char from, aux, to;
    bool isMove;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    char a,b,c;
    cin >> n >> a >> b >> c;
    stack<Task> stk;
    stk.push({n,a,b,c,false});

    while (!stk.empty())
    {
        Task top = stk.top();
        stk.pop();
        
        if (top.isMove)
        {
            cout << top.from << "->" << top.n << "->" << top.to << endl;
        }
        else
        {
            if (top.n==1)
            {
                cout << top.from << "->" << top.n << "->" << top.to << endl;
            }
            else
            {
                stk.push({top.n-1, top.aux, top.from, top.to, false});
                stk.push({top.n, top.from, top.aux, top.to, true});
                stk.push({top.n-1, top.from, top.to, top.aux, false});
            }
        }
    }
    return 0;
}
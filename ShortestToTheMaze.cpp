#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> coord;
int lastRow[5][5], lastCol[5][5];
int drow[4] = {1,-1,0,0};
int dcol[4] = {0,0,1,-1};

int main()
{
    int maze[5][5];
    queue<coord> q;
    stack<coord> route;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> maze[i][j];
        }
    }
    
    q.push({0, 0});
    while (!q.empty())
    {
        coord current = q.front();
        q.pop();

        if (current.first == 4 && current.second == 4) break;

        for (int i = 0; i < 4; i++)
        {
            int k=current.first+drow[i], j=current.second+dcol[i];
            if (k>=0 && j>=0 && k<5 && j<5 && maze[k][j]==0)
            {
                maze[k][j]=-1;
                lastRow[k][j]=current.first;
                lastCol[k][j]=current.second;
                q.push({k, j});
            }
        }
    }
    int a=4,b=4;
    while (a!=0 || b!=0)
    {
        int tempa=a, tempb=b;
        route.push({a,b});
        a=lastRow[tempa][tempb];
        b=lastCol[tempa][tempb];
    }
    cout << "(0, 0)" << endl;
    while (!route.empty())
    {
        coord temp = route.top();
        route.pop();
        cout << "(" << temp.first << ", " << temp.second << ")" << endl;
    }
    return 0;
}
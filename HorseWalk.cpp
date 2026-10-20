#include <bits/stdc++.h>
using namespace std;

static int result = 0;
const int drow[8] = {1,2,2,1,-1,-2,-2,-1};
const int dcol[8] = {2,1,-1,-2,-2,-1,1,2};


void Walk(vector<string> &chessPlate, int row, int col, const int maxRow, const int maxCol)
{
    chessPlate[row][col] = '0';
    bool isWalkable = false;
    for (int i = 0; i < 8; i++)
    {
        if(drow[i]+row < maxRow && drow[i]+row >=0 && dcol[i]+col < maxCol && dcol[i]+col >=0)
        {
            if (chessPlate[drow[i]+row][dcol[i]+col]=='.')
            {
                Walk(chessPlate, drow[i]+row, dcol[i]+col, maxRow, maxCol);
                isWalkable=true;
            }
        }
    }
    if(!isWalkable)
    {
        for (auto &&i : chessPlate)
        {
            if(i.find('.') != string::npos)
            {
                chessPlate[row][col] = '.';
                return;
            }
        }
        result++;
        chessPlate[row][col] = '.';
        return;
    }
    chessPlate[row][col] = '.';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        vector<string> theChess(m);
        for (int i=0; i<m; i++)
        {
            theChess[i].resize(n, '.');
        }
        Walk(theChess, y, x, m, n);
        cout << result << endl;
        result=0;
    }
    return 0;
}
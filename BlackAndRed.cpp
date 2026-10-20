#include <bits/stdc++.h>
using namespace std;

static int result=0;
int drow[4] = {1, -1, 0, 0};
int dcol[4] = {0, 0, 1, -1};

void MazeSearch(vector<string> & maze, int row, int col, int maxRow, int maxCol)
{
    maze[row][col] = '0';
    result++;
    for (int i = 0; i < 4; i++)
    {
        if(drow[i]+row < maxRow && drow[i]+row >=0 && dcol[i]+col < maxCol && dcol[i]+col >= 0)
        {
            if (maze[drow[i]+row][dcol[i]+col] == '.')
            {
                MazeSearch(maze, drow[i]+row, dcol[i]+col, maxRow, maxCol);
            }
        }
    }
}

int main()
{
    int W,H;
    while (1)
    {
        cin >> W >> H;
        if (W==0 && H==0)
        {
            break;
        }
        int row=0,col=0;
        vector<string> theMaze(H);
        for (int i = 0; i < H; i++)
        {
            cin>>theMaze[i];
        }
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if(theMaze[i][j] == '@') 
                {
                    row=i;
                    col=j;
                }
            }
        }
        MazeSearch(theMaze, row, col, H, W);
        cout << result << endl;
        result=0;
    }
    return 0;
}
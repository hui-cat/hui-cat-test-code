#include <bits/stdc++.h>
using namespace std;

int drow[4] = {1, -1, 0, 0};
int dcol[4] = {0, 0, 1, -1};

bool MazeExplore(vector<string>& maze, int row, int col, int brow, int bcol)
{
    if (row == brow && col == bcol)
    {
        return true;
    }
    maze[row][col] = '0';

    for (int i = 0; i < 4; i++)
    {
        if (drow[i]+row<maze.size() && drow[i]+row>=0 && dcol[i]+col<maze[0].size() && dcol[i]+col >=0)
        {
            if (maze[row+drow[i]][col+dcol[i]] == '.')
            {
                if(MazeExplore(maze, row+drow[i], col+dcol[i], brow, bcol)) return true;
            }
        }
    }
    maze[row][col] = '.';
    return false;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int mazeSize, arow, acol, brow, bcol;
        cin >> mazeSize;
        vector<string> theMaze(mazeSize);
        for (int i = 0; i < mazeSize; i++)
        {
            cin >> theMaze[i];
        }
        cin >> arow >> acol >> brow >> bcol;
        if (theMaze[arow][acol] == '#' || theMaze[brow][bcol] == '#')
        {
            cout << "NO" << endl;
            continue;
        }
        if (MazeExplore(theMaze, arow, acol, brow, bcol)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
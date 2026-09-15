#include <bits/stdc++.h>
using namespace std;
void CellKilling(int x, int y); //击杀细胞函数
int m,n;
static int ** squareCell;
int main()
{
    int s=0;
    cin >> m >> n;
    squareCell = new int*[m];
    string * numIn = new string[m];
    for (int i = 0; i < m; i++)
    {
        squareCell[i] = new int[n];
        cin >> numIn[i];
        for (int j = 0; j < n; j++)
        {
            squareCell[i][j] = numIn[i][j] - '0';
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (squareCell[i][j]!=0)
            {
                CellKilling(i, j);
                s++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        delete [] squareCell[i];
    }
    delete [] squareCell;
    delete [] numIn;
    cout << s;
    return 0;
}

void CellKilling(int y, int x)
{
    if (y < 0 || x < 0 || y >= m || x >= n || squareCell[y][x] == 0) {
        return;
    }
    squareCell[y][x] = 0;
    CellKilling(y+1,x);
    CellKilling(y,x+1);
    CellKilling(y-1,x);
    CellKilling(y,x-1);
}
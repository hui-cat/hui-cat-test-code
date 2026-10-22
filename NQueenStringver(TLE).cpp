#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> conclusionSet;
const int drow[4] = {1,1,-1,-1};
const int dcol[4] = {1,-1,-1,1};


void v_queen_replacer(vector<string> & theChess, int row, int col, char replacer, int n)
{
    for (int i = 0; i < theChess.size(); i++)
    {
        theChess[i][col] = replacer;
    }
    for (int i = 0; i < theChess.size(); i++)
    {
        theChess[row][i] = replacer;
    }
    for (int i = 0; i < 4; i++)
    {
        int iRow=row, iCol=col;
        while (iRow<theChess.size() && iCol<theChess.size() && iRow>=0 && iCol>=0)
        {
            theChess[iRow][iCol] = replacer;
            iRow+=drow[i];
            iCol+=dcol[i];
        }
    }
}

void v_search_conclusion(vector<string> & theChess, int currentQueen, int n)
{
    if (currentQueen==n)
    {
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (theChess[i][j]=='1')
                {
                    ans[i] = j+1;
                    break;
                }
            }
        }
        conclusionSet.push_back(ans);
        return;
    }
    vector<string> theChessBak(n);
    for (int j = 0; j < n; j++)
    {
        if(theChess[currentQueen][j]=='0')
        {
            copy(theChess.begin(), theChess.end(), theChessBak.begin());
            v_queen_replacer(theChess, currentQueen, j, '#', n);
            theChess[currentQueen][j]='1';
            v_search_conclusion(theChess, currentQueen+1, n);
            copy(theChessBak.begin(), theChessBak.end(), theChess.begin());
        }
    }   
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> chessPlate(n);
    for (auto &&i : chessPlate)
    {
        i.resize(n,'0');
    }
    v_search_conclusion(chessPlate, 0, n);
    for (int i=0; i < 3; i++)
    {
        for(int j=0; j < n; j++)
        {
            cout << conclusionSet[i][j] << " ";
        }
        cout << endl;
    }
    cout << conclusionSet.size() << endl;
    return 0;
}
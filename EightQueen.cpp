#include <bits/stdc++.h>
using namespace std;

vector<string> chessPlate(8);
vector<vector<string>> conclusionSet;

void v_exclude_queen(vector<string> & theChess, int row, int col)
{

}

void v_search_conclusion(vector<string> & theChess, int currentQueen)
{
    bool isPlaceable = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(theChess[i][j]=='0')
            {
                theChess[i][j]='1';
                
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    for (auto &&i : chessPlate)
    {
        i.resize(8,'0');
    }
    
    return 0;
}
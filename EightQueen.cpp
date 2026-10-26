#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> conclusionSet;
const int drow[4] = {1,1,-1,-1};
const int dcol[4] = {1,-1,-1,1};


void v_queen_replacer(vector<string> & theChess, int row, int col, char replacer)
{
    for (int i = 0; i < 8; i++)
    {
        theChess[i][col] = replacer;
    }
    for (int i = 0; i < 8; i++)
    {
        theChess[row][i] = replacer;
    }
    for (int i = 0; i < 4; i++)
    {
        int iRow=row, iCol=col;
        while (iRow<8 && iCol<8 && iRow>=0 && iCol>=0)
        {
            theChess[iRow][iCol] = replacer;
            iRow+=drow[i];
            iCol+=dcol[i];
        }
    }
}

void v_search_conclusion(vector<string> & theChess, int currentQueen)
{
     if (currentQueen == 8) {
        conclusionSet.push_back(theChess);
        return;
    }
    vector<string> theChessBak(8);
    for (int j = 0; j < 8; j++)
    {
        if(theChess[currentQueen][j]=='0')
        {
            copy(theChess.begin(), theChess.end(), theChessBak.begin());
            v_queen_replacer(theChess, currentQueen, j, '#');
            theChess[currentQueen][j]='1';
            v_search_conclusion(theChess, currentQueen+1);
            copy(theChessBak.begin(), theChessBak.end(), theChess.begin());
        }
    }   
}

int main()
{
    ios::sync_with_stdio(0);
    vector<string> chessPlate(8);
    for (auto &&i : chessPlate)
    {
        i.resize(8,'0');
    }
    v_search_conclusion(chessPlate, 0);
    for (int i=0; i < conclusionSet.size(); i++)
    {
        cout << "No. " << i+1 << endl;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (conclusionSet[i][k][j] == '1') cout << "1";
                else cout << "0";
                
                if (k != 7) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
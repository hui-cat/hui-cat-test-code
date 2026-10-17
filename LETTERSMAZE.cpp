#include <bits/stdc++.h>
using namespace std;

vector<int> results;

void Walk(vector<string> letters,int row, int column, int step)
{
    char s = letters[row][column];
    for (int i=0; i < letters.size(); i++)
    {
        for (int j = 0; j < letters[i].size(); j++)
        {
            if (letters[i][j] == s)
            {
                letters[i][j]='0';
            }
        }
    }
    if (row+1<letters.size())
    {
        if (letters[row+1][column] != '0')
        {
            Walk(letters, row+1, column, step+1);
        }
    }
    if (row-1>=0)
    {
        if (letters[row-1][column] != '0')
        {
            Walk(letters, row-1, column, step+1);
        }
    }
    if (column+1<letters[0].size())
    {
        if (letters[row][column+1] != '0')
        {
            Walk(letters, row, column+1, step+1);
        }
    }
    if (column-1>=0)
    {
        if (letters[row][column-1] != '0')
        {
            Walk(letters, row, column-1, step+1);
        }
    }
    results.push_back(step);
    return;
}

int main()
{
    int R, S;
    cin >> R >> S;
    vector<string> letters(R);
    for (int i = 0; i < R; i++)
    {
        cin >> letters[i];
    }
    Walk(letters, 0, 0, 1);
    auto ans = max_element(results.begin(), results.end());
    cout << *ans << endl;
    return 0;
}
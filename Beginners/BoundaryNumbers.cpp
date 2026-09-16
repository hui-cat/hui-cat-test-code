#include <bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    int m,n,t,s=0;
    cin >> m >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<vector <int>> nums(m, vector<int>(n));
    for (size_t i = 0; i < m; i++)
    {
        int j=0;
        getline(cin, line);
        stringstream ssLine(line);
        while (ssLine >> t)
        {
            nums[i][j] = t;
            j++;
        }
    }
    for (auto &&i : nums[0])
    {
        s+=i;
    }
    for (auto &&i : nums[m-1])
    {
        s+=i;
    }
    for (size_t i = 1; i < m-1; i++)
    {
        s+=nums[i].front() + nums[i].back();
    }
    cout << s;
    return 0;
}
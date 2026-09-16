#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector <int>> nums(5, vector<int>(5));
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            cin >> nums[i][j];
        }
    }
    int m,n;
    cin >> m >> n;
    swap(nums[m-1],nums[n-1]);
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (j==5)
            {
                cout << nums[i][j];
                break;
            }
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
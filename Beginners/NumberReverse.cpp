#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> reverseNum(n);
    reverse_copy(nums.begin(), nums.end(), reverseNum.begin());
    for (auto it = reverseNum.begin(); it != reverseNum.end(); ++it)
    {
        if (it==--reverseNum.end())
        {
            cout << *it;
            break;
        }
        cout << *it << " ";
    }
    return 0;
}
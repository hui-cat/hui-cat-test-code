#include <bits/stdc++.h>
using namespace std;
vector<int> tail;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    tail.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        auto it = lower_bound(tail.begin(), tail.end(), nums[i]);
        if (it == tail.end())
        {
            tail.push_back(nums[i]);
        }
        else 
        {
            *it = nums[i];
        }
    }
    cout << tail.size() << endl;
    return 0;
}
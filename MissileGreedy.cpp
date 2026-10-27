#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> tail_LIS, tail2, missile;
    tail_LIS.reserve(1000000);
    missile.reserve(1000000);
    tail2.reserve(1000000);
    int temp;
    while (cin >> temp)
    {
        missile.push_back(temp);
    }
    for (int i = 0; i < missile.size(); i++)
    {
        auto it = lower_bound(tail_LIS.begin(),tail_LIS.end(),missile[i]);
        if (it == tail_LIS.end())
        {
            tail_LIS.push_back(missile[i]);
        }
        else
        {
            *it = missile[i];
        }
    }
    reverse(missile.begin(), missile.end());
    for (int i = 0; i < missile.size(); i++)
    {
        auto it = upper_bound(tail2.begin(),tail2.end(),missile[i]);
        if (it == tail2.end())
        {
            tail2.push_back(missile[i]);
        }
        else
        {
            *it = missile[i];
        }
    }
    cout << tail2.size() << endl;
    cout << tail_LIS.size() << endl;
    return 0;
}
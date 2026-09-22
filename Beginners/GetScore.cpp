#include <bits/stdc++.h>
using namespace std;
struct StuScore
{
    string stuNum;
    double s;
};

bool compare(const StuScore& i, const StuScore& j)
{
    return i.s>j.s;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<StuScore> stu(n);
    for (auto &&i : stu)
    {
        cin >> i.stuNum;
        cin >> i.s;
    }
    sort(stu.begin(), stu.end(), compare);
    cout << stu[k-1].stuNum << " " << stu[k-1].s;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct ScoreStudent
{
    int s;
    string name;
};

bool compare(ScoreStudent i, ScoreStudent j)
{
    if (i.s != j.s)
    {
        return i.s > j.s;
    }
    return i.name < j.name;
}

int main()
{
    int n;
    cin >> n;
    vector<ScoreStudent> students(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].s;
    }
    sort(students.begin(), students.end(), compare);
    for (size_t i = 0; i < students.size(); i++)
    {
        if (i==n-1)
        {
            cout << students[i].name << " " << students[i].s;
            break;
        }
        cout << students[i].name << " " << students[i].s << endl;
    }
    return 0;
}

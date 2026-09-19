#include <bits/stdc++.h>
using namespace std;
struct ScoreStudent
{
    int s;
    string name;
};

vector<ScoreStudent> BubbleSort(vector<ScoreStudent> List)
{
    
}

int main()
{
    int n;
    cin >> n;
    vector<ScoreStudent> students(n);
    for (auto &&i : students)
    {
        cin >> i.name;
        cin >> i.s;
    }
    sort(students.begin(), students.end());
    for (auto &&i : students)
    {
        cout << i.name << " " << i.s << endl;
    }
    return 0;
}

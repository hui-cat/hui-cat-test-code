#include <bits/stdc++.h>
using namespace std;
struct Student
{
    int score;
    string name;
};

int main()
{
    int n,mI=0;
    cin >> n;
    vector<Student> Students(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> Students[i].score;
        cin >> Students[i].name;
    }
    for (size_t i = 0; i < n; i++)
    {
        if (Students[i].score > Students[mI].score)
        {
            mI=i;
        }
    }
    cout << Students[mI].name;
    return 0;
}
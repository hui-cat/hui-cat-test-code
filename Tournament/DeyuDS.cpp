#include <bits/stdc++.h>
using namespace std;

struct Deyu
{
    string name;
    int score;
    int rank;
};

bool compare(const Deyu& s, const Deyu& n)
{
    return s.score > n.score;
}

int main()
{
    int n;
    cin >> n;
    vector<Deyu> Students(n), stuCpy(n);
    unordered_map<string, double> stuScore;
    
    for (int i = 0; i < n; i++)
    {
        cin >> Students[i].name >> Students[i].score;
    }
    
    copy(Students.begin(), Students.end(), stuCpy.begin());
    sort(stuCpy.begin(), stuCpy.end(), compare);
    
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && stuCpy[i].score == stuCpy[i - 1].score)
        {
            stuCpy[i].rank = stuCpy[i - 1].rank;
            continue;
        }
        stuCpy[i].rank = i + 1;
    }
    
    for (auto &&i : stuCpy)
    {
        if (i.score == 0) 
        {
            stuScore.insert({i.name, 0.0});
            continue;
        }
        
        int s = 100 * (n - i.rank) / n;
        
        if (s >= 90) stuScore.insert({i.name, 0.8});
        else if (s >= 75) stuScore.insert({i.name, 0.7});
        else if (s >= 60) stuScore.insert({i.name, 0.6});
        else if (s >= 40) stuScore.insert({i.name, 0.5});
        else if (s >= 25) stuScore.insert({i.name, 0.4});
        else if (s >= 10) stuScore.insert({i.name, 0.3});
        else stuScore.insert({i.name, 0.2});
    }
    
    for (int i = 0; i < n; i++)
    {
        double deyu = stuScore[Students[i].name];
        if (deyu == 0.0) {
            cout << 0 << endl;
        } else {
            cout << fixed << setprecision(1) << deyu << endl;
        }
    }
    return 0;
}
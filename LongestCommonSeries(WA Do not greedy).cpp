#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    vector<bool> bO(b.size());
    vector<int> result;
    fill(bO.begin(), bO.end(), false);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j] && !bO[j])
            {
                auto it = upper_bound(result.begin(),result.end(), j);
                if (it == result.end())
                {
                    result.push_back(j);
                }
                else
                {
                    *it = j;
                }
                bO[j]=true;
                break;
            }
        }
    }
    cout << result.size() << endl;
    return 0;
}
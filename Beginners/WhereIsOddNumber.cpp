#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> oddNum;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        if (input % 2 != 0)
        {
            oddNum.push_back(input);
        }
    }
    sort(oddNum.begin(), oddNum.end());
    for (size_t i = 0; i < oddNum.size(); i++)
    {
        if (i==oddNum.size()-1)
        {
            cout << oddNum[i] << endl;
            break;
        }
        cout << oddNum[i] << ",";
    }
    return 0;
}
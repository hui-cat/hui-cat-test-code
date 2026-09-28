#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> letters(26);
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        int index = input[i] - 'a';
        letters[index]++;
    }
    auto out = max_element(letters.begin(), letters.end());
    int index = out-letters.begin() + 'a';
    cout << (char) index << " " << *out;
    return 0;
}
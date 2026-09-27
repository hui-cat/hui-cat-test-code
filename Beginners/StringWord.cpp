#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> words;
    string input, temp;
    getline(cin, input);
    stringstream inputSentence;
    inputSentence << input;
    while (inputSentence >> temp)
    {
        words.push_back(temp);
    }
    sort(words.begin(), words.end());
    for (auto &&i : words)
    {
        cout << i << endl;
    }
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input, output;
    int a;
    cin >> input >> a;
    for (size_t i = 0; i < input.length(); i++)
    {
        output += input[i] + a;
    }
    cout << output << endl;
    return 0;
}
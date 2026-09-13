#include <iostream>

using namespace std;

bool Lights[2000000];

int main()
{
    for (int i = 0; i < 2000000; i++)
    {
        Lights[i] = false;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double a;
        int t;
        cin >> a >> t;
        for (int j = 1; j <= t; j++)
        {
            int index = (int)(a * j);
            Lights[index] ^= 1;
        }
    }
    for (int i = 2; i < 2000000; i++)
    {
        if (Lights[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
static vector<int> primes = {2};
bool IsPrime(int n)
{
    for (int i : primes)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    primes.push_back(n);
    return true;
}

int main()
{
    int n,s=1;
    cin >> n;
    for (size_t i = 3; i <= n; i++)
    {
        if (IsPrime(i))
        {
            s++;
        }
    }
    cout << s;
}
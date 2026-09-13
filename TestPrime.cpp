#include <iostream>

using namespace std;

bool isPrimeNumber[10001];

int main()
{
    int primeNumberSize=0;
    for (size_t i = 1; i < 10001; i++)
    {
        isPrimeNumber[i] = true;
    }
    isPrimeNumber[0] = false;
    isPrimeNumber[1] = false;
    for (size_t i = 2; i <= 10000; i++)
    {
        for (size_t j = 2; j < i; j++)
        {
            if (i%j==0)
            {
                isPrimeNumber[i] = false;
                break;
            }
        }
    }
    for (size_t i = 0; i < 10001; i++)
    {
        if (isPrimeNumber[i])
        {
            primeNumberSize++;
        }
    }
    int * primeNumbers = new int[primeNumberSize];
    int primePosition=0;
    for (size_t i = 0; i < 10001; i++)
    {
        if (isPrimeNumber[i])
        {
            primeNumbers[primePosition]=i;
            primePosition++;
        }
    }
    for (size_t i = 0; i < primeNumberSize; i++)
    {
        cout << primeNumbers[i] << endl;
    }
    return 0;
}
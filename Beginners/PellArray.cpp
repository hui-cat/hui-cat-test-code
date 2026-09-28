#include <bits/stdc++.h>
using namespace std;

int pellSequence[1000005];

void init()
{
    pellSequence[0]=1;
    pellSequence[1]=2;
    for (size_t i = 2; i < 1000005; i++)
    {
        pellSequence[i] = (pellSequence[i-2]+2*pellSequence[i-1]) % 32767;
    }
}

int main()
{
    init();
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        long index;
        cin >> index;
        cout << pellSequence[index-1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

char Elysia[7] = "Elysia";

long long FindNext(int indexSeq, long long index, string str)
{
    long long result = 0;
    for (long long i = index; i < str.size(); i++)
    {
        if (str[i] == Elysia[indexSeq])
        {
            if(indexSeq!=5)
            {
                long long a = FindNext(indexSeq+1, i, str);
                result += a;
            } else
            {
                result++;
            }
        }
    }
    return result;
}

long long Find(string str)
{
    long long result=0;
    for (long long i = 0; i < str.size(); i++)
    {
        if (str[i] == 'E')
        {
            result += FindNext(1, i, str);
        }
    }
    return result;
}

int main()
{
    int n;
    string str;
    cin >> n >> str;
    long long count = Find(str);
    cout << count << endl;
    return 0;
}
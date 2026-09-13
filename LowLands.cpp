#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int * nums = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int l=0;
    bool inLow = false;
    for (size_t i = 1; i < n; i++)
    {
        if (nums[i] < nums[i-1] && !inLow)
        {
            l++;
            inLow = true;
        }
        if (nums[i] > nums[i-1])
        {
            inLow = false;
        }
    }
    cout << --l;
}
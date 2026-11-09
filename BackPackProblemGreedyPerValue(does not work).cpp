#include <bits/stdc++.h>
using namespace std;
struct item
{
    int weight;
    int value;
    double valuePerWeight;
};

bool cmp(const item & a, const item & b)
{
    return a.valuePerWeight < b.valuePerWeight;
}

int main()
{
    int capacity, itemCount;
    cin >> capacity >> itemCount;
    vector<item> items(itemCount);
    vector<item> backpack;
    int cur_capacity=0;
    int result=0;
    for (int i = 0; i < itemCount; i++)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].valuePerWeight = (double)items[i].value / (double)items[i].weight;
    }
    for (int i = 0; i < itemCount; i++)
    {
        if (cur_capacity + items[i].weight <= capacity)
        {
            backpack.push_back(items[i]);
            cur_capacity += items[i].weight;
            result += items[i].value;
            sort(backpack.begin(), backpack.end(), cmp);
        }
        else
        {
            for (auto it = backpack.begin(); it != backpack.end(); it++)
            {
                cur_capacity = cur_capacity - it->weight + items[i].weight;
                if (cur_capacity > capacity)
                {
                    cur_capacity = cur_capacity - items[i].weight + it->weight;
                    continue;
                }
                else
                {
                    *it = items[i];
                    result = result - it->value + items[i].value;
                    break;
                }
                
            }
            

        }
    }
    cout << result << endl;
    return 0;
}
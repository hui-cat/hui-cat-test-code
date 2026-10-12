#include <bits/stdc++.h>
using namespace std;
int n;
char a,b,c;

void HanoTower(int n, char from, char aux, char to)
{
    if (n==1)
    {
        cout << from << "->" << n << "->" << to << endl;
        return;
    }
    
    HanoTower(n-1, from, to, aux);
    cout << from << "->" << n << "->" << to << endl;
    HanoTower(n-1, aux, from, to);
}
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    HanoTower(n,a,c,b);
    return 0;
}
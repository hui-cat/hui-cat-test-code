#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double x,a,y,b;
    cin >> x >> a >> y >> b;
    double j = (y*b-x*a) / (b-a);
    cout << std::fixed << std::setprecision(2) << j << endl;
    return 0;
}
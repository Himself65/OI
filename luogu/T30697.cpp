#include <cmath>
#include <iostream>
using namespace std;
double v, st;
double h, s, vx, vy, t;
int main()
{
    cin >> v >> st;
    vx = v * sin(st);
    vy = v * cos(st);
    t = vy / 10;
    h = 5 * t * t;
    s = vx * t;
    cout << s << " " << h;
    return 0;
}
// h = 1 / 2  * v * t * t
// v = v - at
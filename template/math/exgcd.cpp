#include <cstdio>
#include <iostream>
using namespace std;
void exgcd(int _a, int _b, int &_x, int &_y, int &_d)
{
    if (!_b)
    {
        _x = 1;
        _y = 0;
        _d = _a;
    }
    else
    {
        exgcd(_b, _a % _b, _y, _x, _d);
        _y -= _x * (_a / _b);
    }
}
int main()
{
    int a, b, x, y, d;
    a = 252;
    b = 105;
    exgcd(a, b, x, y, d);
    cout << x << " " << y << " " << d << endl;
    system("pause");
    return 0;
}
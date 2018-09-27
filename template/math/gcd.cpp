#include <cstdio>
#include <iostream>
using namespace std;
void gcd1(int a, int b, int &d)
{
    if (!b)
        d = a;
    else // 注意，这里要 else 或者及时 return
        gcd1(b, a % b, d);
}
int gcd2(int a, int b)
{
    if (!b) // b == 0
        return a;
    return gcd2(b, a % b);
}
int x, y, k;
int main()
{
    x = 252;
    y = 105;
    gcd1(x, y, k);
    cout << k << endl;
    k = gcd2(x, y);
    cout << k << endl;
    system("pause");
    return 0;
}
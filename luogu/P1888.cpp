#include <cstdio>
#include <iostream>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b)
{
    if (b == 1)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    // 只处理a和b
    a = min(a, min(b, c));
    b = max(a, max(a, b));
    int d = gcd(a, b);
    cout << a / d << "/" << b;
    return 0;
}
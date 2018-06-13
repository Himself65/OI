#include <iostream>
#include <string>
using namespace std;
int n;
inline string solve(int x, int i = 0, string s = string(""))
{
    if (x == 0)
        return "0";
    do
        // 直到为 1 时候
        if (x & 1)
            s = (i == 1 ? "2" : "2(" + solve(i) + ")") + (s == "" ? "" : "+") + s;
    while (++i, x >>= 1);
    return s;
}
int main()
{
    cin >> n;
    cout << solve(n);
    return 0;
}
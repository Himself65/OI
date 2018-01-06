#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int x[10];
void solve(int n)
{
    if (n==9)
    {
        int a = x[1] * 100 + x[2] * 10 + x[3];
        int b = x[4] * 100 + x[5] * 10 + x[6];
        int c = x[7] * 100 + x[8] * 10 + x[9];
        b /= 2;
        c /= 3;
        if (a == b && b == c && a == c)
            printf("%d %d %d\n", a, b * 2, c * 3);
        return;
    }
    for (int i = 1; i <= 9;i++)
    {
        x[n] = i;
        solve(n + 1);
    }
}

int main()
{
    solve(1);
    return 0;
}
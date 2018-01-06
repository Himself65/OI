#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int x[10];
void solve()
{
    for (int i = 1; i <= 9; i++)
    {
        x[i] = i;
    }
    do
    {
        int a = x[1] * 100 + x[2] * 10 + x[3];
        int b = x[4] * 100 + x[5] * 10 + x[6];
        int c = x[7] * 100 + x[8] * 10 + x[9];
        b /= 2;
        c /= 3;
        if (a == b && b == c && a == c)
            printf("%d %d %d\n", a, b * 2, c * 3);
    } while (next_permutation(x + 1, x + 10));
}

int main()
{
    solve();
    return 0;
}
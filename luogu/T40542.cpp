#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e3 + 5;
int n;
int a[maxn];
int f[maxn][maxn][2];
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
// 0 -> A
// 1 -> B
inline int solve(int l, int r, int who)
{
    if (l == r)
        return f[l][r][who] = a[l];
    else if (f[l][r][who])
        return f[l][r][who];
    else if (who == 0)
        return f[l][r][who] = min(solve(l + 1, r, 1), solve(l, r - 1, 1));
    else
        return f[l][r][who] = max(solve(l + 1, r, 0), solve(l, r - 1, 0));
}
#define LOCALN
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", solve(1, n, 0));
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}
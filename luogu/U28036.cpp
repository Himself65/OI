#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e+6 + 5;
const int maxx = 2000 + 5;
const long long mod = 998244353;
int n, q;
long long a[maxn], f[maxx][maxx];
int main()
{
    f[0][0] = 1;
    for (int i = 1; i <= 2000; i++)
    {
        f[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
            if (f[i][j] >= mod)
                f[i][j] -= mod;
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    scanf("%d", &q);
    while (q--)
    {
        int x, y;
        long long ans = 0;
        scanf("%d%d", &x, &y);
        for (int i = 0, j = y; i <= x; ++i)
        {
            ans += 1ll * f[x][i] * a[j] % mod;
            if (ans >= mod)
                ans -= mod;
            ++j;
            if (j > n)
                j = 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
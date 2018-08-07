#include <cmath>
#include <iostream>
#define INIT                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define ll long long
#define lll __int128
using namespace std;
const int maxn = 100 + 5;
ll a[maxn];
ll f[maxn][maxn];
ll p[maxn] = {1};
int m, n;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

inline int max(int a, int b, int c, int d)
{
    return max(a, max(b, max(c, d)));
}

inline void init()
{
    for (int i = 1; i <= 100; i++)
        p[i] = p[i - 1] << 1;
}
ll ans;
inline int solve()
{
}
int main()
{
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &a[m]);
        }
        ans += solve();
    }
    printf("%lld", ans);
    return 0;
}
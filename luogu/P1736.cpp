#define LOCAL // For Windows
#define TEST
// #define DATA
#define HAND
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int maxn = 2e3 + 5e2 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD
{
int n, m, ans1, ans2;
int a[maxn][maxn], f[maxn][maxn], s1[maxn][maxn], s2[maxn][maxn];
inline void solve()
{
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= m; ++j)
        {
            if (!a[i][j])
            {
                s1[i][j] = s1[i][j - 1] + 1;
                s2[i][j] = s2[i - 1][j] + 1;
            }
            if (a[i][j])
                f[i][j] = min(f[i - 1][j - 1], min(s1[i][j - 1], s2[i - 1][j])) + 1;
            ans1 = max(ans1, f[i][j]);
        }
    memset(f, 0, sizeof(f));
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    for (register int i = 1; i <= n; ++i)
        for (register int j = m; j >= 1; --j)
        {
            if (!a[i][j])
            {
                s1[i][j] = s1[i][j + 1] + 1;
                s2[i][j] = s2[i - 1][j] + 1;
            }
            if (a[i][j])
                f[i][j] = min(f[i - 1][j + 1], min(s1[i][j + 1], s2[i - 1][j])) + 1;
            ans2 = max(ans2, f[i][j]);
        }
    printf("%d\n", max(ans1, ans2));
#ifdef TEST
    for (register int i = 1; i <= n; ++i)
    {
        for (register int j = 1; j <= m; ++j)
            printf("%d ", f[i][j]);
        printf("\n");
    }
#endif
}
} // namespace BREAD
int main()
{
#ifdef LOCAL
#ifdef DATA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#endif
    BREAD::solve();
    // INIT_CIN;
#ifdef LOCAL
#ifdef HAND
    system("pause");
#endif
#endif
    return 0;
}

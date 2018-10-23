#define LOCAL // For Windows
#define TEST
#define DATA
// #define HAND
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
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
const int maxn = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD
{
int n, m, ans;
bool a[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn], up[maxn][maxn];
inline void solve()
{
    scanf("%d%d", &n, &m);
    char ch;
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= m; j++)
            scanf(" %c", &ch), a[i][j] = (ch == 'F' ? true : false),
                               up[i][j] = 1, r[i][j] = l[i][j] = j;
#ifdef TEST
    for (register int i = 1; i <= n; ++i)
    {
        for (register int j = 1; j <= m; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
#endif
    // 分别处理 l 和 r
    // 用数组l，r记录某点向左和向右能到达的最远点的纵坐标
    // 用数组up记录某点向上能到达的最远距离。
    for (register int i = 1; i <= n; ++i)
        for (register int j = 2; j <= m; ++j)
            if (a[i][j] && a[i][j - 1])
                l[i][j] = l[i][j - 1];
    for (register int i = 1; i <= n; ++i)
        for (register int j = m - 1; j >= 1; --j)
            if (a[i][j] && a[i][j + 1])
                r[i][j] = r[i][j + 1];
    // solve
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= m; ++j)
        {
            if (i > 1 && a[i][j] && a[i - 1][j])
                r[i][j] = min(r[i][j], r[i - 1][j]),
                l[i][j] = max(l[i][j], l[i - 1][j]),
                up[i][j] = up[i - 1][j] + 1;
            ans = max(ans, (r[i][j] - l[i][j] + 1) * up[i][j]);
        }
    printf("%d\n", ans * 3);
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
#ifdef LOCAL
#ifdef HAND
    system("pause");
#endif
#endif
    return 0;
}
// #ifdef TEST
//     for (register int i = 1; i <= n; ++i)
//     {
//         for (register int j = 1; j <= m; ++j)
//         {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
//     for (register int i = 1; i <= n; ++i)
//     {
//         for (register int j = 1; j <= m; ++j)
//         {
//             printf("%d ", l[i][j]);
//         }
//         printf("\n");
//     }
//     for (register int i = 1; i <= n; ++i)
//     {
//         for (register int j = 1; j <= m; ++j)
//         {
//             printf("%d ", r[i][j]);
//         }
//         printf("\n");
//     }
//     for (register int i = 1; i <= n; ++i)
//     {
//         for (register int j = 1; j <= m; ++j)
//         {
//             printf("%d ", up[i][j]);
//         }
//         printf("\n");
//     }
// #endif
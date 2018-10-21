#define LOCAL // For Windows
// #define TEST
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
const int maxn = 2e6 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD
{
int n, k, p;
int now, color, price, ans;
int last[maxn], cnt[maxn], sum[maxn];
inline void solve()
{
    scanf("%d%d%d", &n, &k, &p);
    for (register int i = 1; i <= n; i++)
    {
        scanf("%d%d", &color, &price); // 颜色 价格
        if (price <= p)                // 价格小于需求，可以到这个地方
            now = i;                   //
        if (now >= last[color])        // 当前位置大于上一次出现颜色位置
            sum[color] = cnt[color];   // 搭配方案数+=当前颜色数
        last[color] = i;               // 最后出现该颜色的位置
        ans += sum[color];             //
        cnt[color]++;                  // 该颜色客栈++
    }
    printf("%d", ans);
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
#ifdef TEST
    printf("TEST");
#endif
#ifdef LOCAL
#ifdef HAND
    system("pause");
#endif
#endif
    return 0;
}

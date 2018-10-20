#define LOCAL
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
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD
{
int n, m;
int a[maxn], fa[maxn], rk[maxn], p[maxn], on[maxn], add[maxn];
vector<int> son[maxn];
inline int find(int x) { return x == fa[x] ? x : find(fa[x]); }
inline void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    if (rk[x] > rk[y])
        swap(x, y);
    add[x] -= add[y];
    fa[x] = y;
    if (rk[x] == rk[y])
        rk[y]++;
}
inline int eval(int x)
{
    int s = 0, y = x;
    while (fa[y] != y)
        s += add[y], y = fa[y];
    s += add[y];
    return s;
}
inline void solve()
{
    scanf("%d", &n);
    for (register int i = 2; i <= n; i++)
    {
        scanf("%d", a + i);
        son[a[i]].push_back(i);
    }
    for (register int i = 1; i <= n; i++)
        scanf("%d", p + i);
    for (register int i = 1; i <= n; i++)
        fa[i] = i;
    for (register int t = n; t >= 1; t--)
    {
        int i = p[t];
        on[i] = 1;
        for (register size_t j = 0; j < son[i].size(); j++)
        {
            int k = son[i][j];
            if (on[k])
                merge(i, k);
        }
        add[find(i)]++;
        if (on[a[i]])
            merge(i, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = eval(i);
        printf("%d\n", ans);
    }
}
} // namespace BREAD
int main()
{
    // INIT_CIN;
    BREAD::solve();
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

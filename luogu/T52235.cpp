#define LOCAL // For Windows
#define TEST
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
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD
{
int n, m;
int a[maxn];
int p[maxn];
inline int find(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = find(p[x]);
}
inline void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    else
        p[x] = y;
}
inline void solve()
{

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (register int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (register int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(u, v);
    }
    bool ok = true;
    for (register int i = 1; i <= n; i++)
    {
        if (i != a[i])
        {
            if (find(a[i]) != find(i))
            {
                ok = false;
                break;
            }
        }
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";
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
    // INIT_CIN;
    BREAD::solve();
#ifdef LOCAL
#ifdef HAND
    system("pause");
#endif
#endif
    return 0;
}

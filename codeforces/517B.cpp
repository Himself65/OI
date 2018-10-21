// #define HAND
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

int n, limit;
int a[maxn], b[maxn], c[maxn];
inline bool dfs(int x)
{
    for (register int k = 0; k <= 3; k++)
    {
        if ((a[x] == (c[x + 1] | k)) && (b[x] == (c[x + 1] & k)))
        {
            bool o = false;
            c[x] = k;
            if (x == 1)
                return true;
            o = dfs(x - 1);
            if (o)
                return o;
        }
        else if (k == 3)
        {
            return false;
        }
    }
}
inline void solve()
{
    scanf("%d", &n);
    for (register int i = 1; i <= n - 1; i++)
    {
        scanf("%d", a + i);
    }
    for (register int i = 1; i <= n - 1; i++)
    {
        scanf("%d", b + i);
    }
    bool ok = false;
    for (register int i = 0; i <= 3; i++)
    {
        c[n] = i;
        ok = dfs(n - 1);
        if (ok)
            break;
    }
    if (!ok)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        for (register int i = 1; i <= n; i++)
        {
            printf("%d ", c[i]);
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef HAND
    system("pause");
#endif

    return 0;
}

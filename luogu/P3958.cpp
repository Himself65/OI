#define LOCAL // For Windows
#define TEST
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
const int maxn = 1e4 + 5;
struct Node
{
    ll x, y, z;
} a[maxn];
int p[maxn];
ll n, h, r;
// data
inline void init(int n)
{
    for (register int i = 0; i <= n + 1; i++)
        p[i] = i;
}
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
        p[y] = x;
}
inline bool is_close(int x, int y)
{
    Node &px = a[x], &py = a[y];
    return sqrt((px.x - py.x) * (px.x - py.x) + (px.y - py.y) * (px.y - py.y) + (px.z - py.z) * (px.z - py.z)) <= 2 * r;
}
int T;
int main()
{
#ifdef LOCAL
    freopen("in2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &h, &r);
        init(n); // 注意初始化
#ifdef TEST
        printf("%lld %lld %lld\n", n, h, r);
#endif
        for (register int i = 1; i <= n; i++)
        {
            ll x, y, z;
            scanf("%lld%lld%lld", &x, &y, &z);
            a[i].x = x, a[i].y = y, a[i].z = z;
            if (z - r <= 0) // 假定 0 为最下方
                merge(i, 0);
            if (z + r >= h)
                merge(i, n + 1);
            for (register int j = 1; j < i; j++)
            {
                if (find(i) == find(j))
                    continue;
                if (is_close(i, j))
                {
                    merge(i, j);
#ifdef TEST
                    printf("points %d and %d have merged\n", i, j);
#endif
                }
            }
        }
        if (find(0) == find(n + 1)) // 假定 n+1 为最上方
            printf("Yes\n");
        else
            printf("No\n");
#ifdef TEST
        for (int i = 0; i <= n + 1; i++)
        {
            printf("point %d's father is %d\n", i, find(i));
        }
#endif
    }
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
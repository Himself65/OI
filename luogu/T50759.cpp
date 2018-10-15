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
const int maxn = 2e5 + 5;
int n, m, k;
ll fac[maxn], inv_fac[maxn];
struct Node
{
    int x, y;
    bool operator<(const Node &p) const
    {
        return x + y < p.x + p.y;
    }
} a[maxn];
const int mod = 1e9 + 7;
inline ll qpow(ll x, ll y)
{
    ll res = 1;
    for (int i = 1; i <= y; i <<= 1)
    {
        if (i & y)
            res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
    }
    return res;
}
inline void init()
{
    inv_fac[0] = fac[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv_fac[i] = qpow(fac[i], mod - 2);
    }
}
inline ll C(int n, int m)
{
    // n>=m
    if (m == 0 || m == n)
        return 1;
    ll res = ((fac[n] * inv_fac[m] % mod) * inv_fac[n - m]) % mod;
    return res;
}
int main()
{
    INIT_CIN; // std::cin的优化
    scanf("%d%d%d", &n, &m, &k);
    init();
    for (register int i = 1; i <= k; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    a[++k].x = 1;
    a[k].y = 1;
    a[++k].x = n;
    a[k].y = m;
    sort(a + 1, a + k + 1);
    ll ans = 1;
    for (register int i = 2; i <= k; i++)
    {
        int dx = a[i].x - a[i - 1].x;
        int dy = a[i].y - a[i - 1].y;
        if (dx < 0 || dy < 0)
        {
            ans = 0;
            break;
        }
        ans = ans * C(dx + dy, dx) % mod;
    }
    printf("%lld", ans);
#ifdef TEST
#endif
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
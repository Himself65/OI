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
const int maxn = 1e5 + 5;
int n, q;
ll mod = 1e9 + 7;
ll a[maxn], b[maxn], c[maxn], s[maxn];
ll ans = 1, no;
inline ll min(ll a, ll b) { return a < b ? a : b; }
inline ll max(ll a, ll b) { return a > b ? a : b; }
inline ll f(ll xa, ll xb)
{
    ll xc = 1;
    while (xb)
    {
        if (xb & 1)
            xc = (xc * xa) % mod;
        xb >>= 1;
        xa = (xa * xa) % mod;
    }
    return xc;
}
inline ll divi(ll xa, ll xb)
{
    return (xa * f(xb, mod - 2)) % mod;
}
inline void rm(ll val)
{
    if (val)
        ans = divi(ans, val);
    else
        no--;
}
inline void add(ll val)
{
    if (val)
        ans = (ans * val) % mod;
    else
        no++;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        c[i] = max(c[i - 1], a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
        add(min(c[i], b[i]));
    }
    for (int i = 1; i <= q; i++)
    {
        int op, x;
        ll y;
        scanf("%d %d %lld", &op, &x, &y);
        if (op == 1) // B
        {
            rm(min(b[x], c[x]));
            // ans = (ans / min(b[x], c[x]));
            b[x] = y % mod;
            // ans = (ans * min(b[x], c[x])) % mod;
            add(min(b[x], c[x]));
        }
        else // A
        {
            while (x <= n && c[x] < y)
            {
                rm(min(b[x], c[x]));
                c[x] = y;
                add(min(b[x], c[x]));
                x++;
            }
        }
        printf("%lld\n", no ? 0 : ans);
    }
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
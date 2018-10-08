#define LOCAL
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2e6 + 5;
typedef long long ll;
ll n, m, s, sum1[maxn], sum2[maxn];
struct Node
{
    ll w, v;
} a[maxn];
struct ask
{
    ll l, r;
} b[maxn];
ll now;
inline void solve(ll l, ll r)
{
    if (l == r)
        return;
    ll mid = (l + r) / 2;
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    for (ll i = 1; i <= n; i++)
    {
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        if (a[i].w >= mid)
        {
            sum1[i]++;
            sum2[i] += a[i].v;
        }
    }
    ll y = 0;
    for (ll i = 1; i <= m; i++)
    {
        y += ((sum1[b[i].r] - sum1[b[i].l - 1]) * (sum2[b[i].r] - sum2[b[i].l - 1]));
    }
    if (abs(s - y) < abs(s - now))
        now = y;
    if (s > y)
        solve(l, mid);
    else if (s == y)
    {
        now = s;
        return;
    }
    else
        solve(mid + 1, r);
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &s);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &a[i].w, &a[i].v);
    }
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &b[i].l, &b[i].r);
    }
    solve(1, 100000);
    printf("%lld", abs(s - now));
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}
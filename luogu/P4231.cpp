#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e7 + 5;
ll n, m;
ll l, r, s, e, sum, maxa, ans;
struct Node
{
    ll s, v, n;
} d[maxn];
ll a[maxn];
ll h[maxn], cnt;
inline void set(ll i, ll s, ll v)
{
    d[++cnt].s = s;
    d[cnt].v = v;
    d[cnt].n = h[i];
    h[i] = cnt;
}
inline ll max(ll a,ll b)
{
    return a > b ? a : b;
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m;
    while (m--)
    {
        cin >> l >> r >> s >> e;
        ll d = (e - s) / (r - l);
        a[l] += s;
        set(l, s, d);
        set(r + 1, -e - d, -d);
    }
    for (ll i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + sum;
        for (ll j = h[i]; j; j = d[j].n)
        {
            sum += d[j].v;
            a[i] += d[j].s;
        }
        maxa = max(maxa, a[i]);
        ans ^= a[i];
    }
    cout << ans << " " << maxa;
    return 0;
}
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define lc(p) (p << 1)
#define rc(p) (p << 1 | 1)
const int maxn = 100000 + 5;
ll mod;
ll a[maxn];
struct Node
{
    ll v, mul, add;
    Node()
    {
        mul = 1;
        add = 0;
        v = 0;
    }
} st[maxn << 2];

void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        st[p].v = a[l];
    }
    else
    {
        ll m = (l + r) / 2;
        build(lc(p), l, m);
        build(rc(p), m + 1, r);
        st[p].v = st[lc(p)].v + st[rc(p)].v;
    }
    st[p].v %= mod;
    return;
}

void push_down(ll p, ll l, ll r)
{
    ll m = (l + r) / 2;
    //
    st[lc(p)].v = (st[lc(p)].v * st[p].mul + st[p].add * (m - l + 1)) % mod;
    st[rc(p)].v = (st[rc(p)].v * st[p].mul + st[p].add * (r - m)) % mod;
    // update
    st[lc(p)].mul = (st[lc(p)].mul * st[p].mul) % mod;
    st[rc(p)].mul = (st[rc(p)].mul * st[p].mul) % mod;
    st[lc(p)].add = (st[lc(p)].add * st[p].mul + st[p].add) % mod;
    st[rc(p)].add = (st[rc(p)].add * st[p].mul + st[p].add) % mod;
    // reset
    st[p].mul = 1;
    st[p].add = 0;
}

void ud1(ll p, ll nl, ll nr, ll l, ll r, ll k)
{
    if (r < nl || nr < l)
    {
        return;
    }
    if (l <= nl && nr <= r)
    {
        st[p].v = (st[p].v * k) % mod;
        st[p].mul = (st[p].mul * k) % mod;
        st[p].add = (st[p].add * k) % mod;
        return;
    }
    push_down(p, nl, nr);
    int m = (nl + nr) / 2;
    ud1(lc(p), nl, m, l, r, k);
    ud1(rc(p), m + 1, nr, l, r, k);
    st[p].v = (st[lc(p)].v + st[rc(p)].v) % mod;
    return;
}

inline void ud2(ll p, ll nl, ll nr, ll l, ll r, ll k)
{
    if (r < nl || nr < l)
    {
        return;
    }
    if (l <= nl && nr <= r)
    {
        st[p].add = (st[p].add + k) % mod;
        st[p].v = (st[p].v + k * (nr - nl + 1)) % mod;
        return;
    }
    push_down(p, nl, nr);
    int m = (nl + nr) / 2;
    ud2(lc(p), nl, m, l, r, k);
    ud2(rc(p), m + 1, nr, l, r, k);
    st[p].v = (st[lc(p)].v + st[rc(p)].v) % mod;
    return;
}

inline ll query(ll p, ll nl, ll nr, ll l, ll r)
{
    if (r < nl || nr < l)
    {
        return 0;
    }
    if (l <= nl && nr <= r)
    {
        return st[p].v;
    }
    push_down(p, nl, nr);
    int m = (nl + nr) / 2;
    return (query(lc(p), nl, m, l, r) + query(rc(p), m + 1, nr, l, r)) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //
    ll n, m;
    scanf("%lld%lld%lld", &n, &m, &mod);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        ll chk;
        scanf("%lld", &chk);
        ll p, y, k;
        if (chk == 1)
        {
            scanf("%lld%lld%lld", &p, &y, &k);
            ud1(1, 1, n, p, y, k);
        }
        else if (chk == 2)
        {
            scanf("%lld%lld%lld", &p, &y, &k);
            ud2(1, 1, n, p, y, k);
        }
        else
        {
            scanf("%lld%lld", &p, &y);
            printf("%lld\n", query(1, 1, n, p, y));
        }
    }
    return 0;
}
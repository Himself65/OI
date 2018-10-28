#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
#define LEFT_SON(x) (x << 1)
#define RIGHT_SON(x) (x << 1 | 1)
const int maxn = 100000 + 5;
ll n, m;
inline ll max(ll a, ll b);
inline ll min(ll a, ll b);
ll ans[maxn << 2], tag[maxn << 2];
ll a[maxn];
inline void push_up_sum(ll p)
{
    ans[p] = ans[LEFT_SON(p)] + ans[RIGHT_SON(p)];
}

inline void build(ll l, ll r, ll p)
{
    tag[p] = 0; // 这个其实不用赋值也可以，因为在全局变量默认为0
    if (l == r) // 达到子节点
    {
        ans[p] = a[l];
        return;
    }
    else
    {
        ll mid = (l + r) >> 1;
        build(l, mid, LEFT_SON(p));
        build(mid + 1, r, RIGHT_SON(p));
        push_up_sum(p);
    }
}
inline void f(ll l, ll r, ll p, ll k)
{
    tag[p] += k;
    ans[p] += k * (r - l + 1);
}
inline void push_down(ll l, ll r, ll p)
{
    ll mid = (l + r) >> 1;
    f(l, mid, LEFT_SON(p), tag[p]);
    f(mid + 1, r, RIGHT_SON(p), tag[p]);
    tag[p] = 0;
}
inline void update(ll l, ll r, ll p, ll nl, ll nr, ll k)
{
    if (nl <= l && r <= nr)
    {
        ans[p] += k * (r - l + 1);
        tag[p] += k;
        return;
    }
    push_down(l, r, p);
    ll mid = (l + r) >> 1;
    if (nl <= mid)
        update(l, mid, LEFT_SON(p), nl, nr, k);
    if (nr > mid)
        update(mid + 1, r, RIGHT_SON(p), nl, nr, k);
    push_up_sum(p);
}
inline ll query(ll l, ll r, ll p, ll qx, ll qy)
{
    ll res = 0;
    if (qx <= l && r <= qy)
        return ans[p];
    ll mid = (l + r) >> 1;
    push_down(l, r, p);
    if (qx <= mid)
        res += query(l, mid, LEFT_SON(p), qx, qy);
    if (qy > mid)
        res += query(mid + 1, r, RIGHT_SON(p), qx, qy);
    return res;
}
int main()
{
    INIT_CIN;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int b, c, d, e, f, ps;
        cin >> ps;
        if (ps == 1)
        {
            cin >> b >> c >> d;
            update(1, n, 1, b, c, d);
        }
        else
        {
            cin >> e >> f;
            cout << query(1, n, 1, e, f) << endl;
        }
    }
    return 0;
}

inline ll max(ll a, ll b)
{
    return a > b ? a : b;
}
inline ll min(ll a, ll b)
{
    return a < b ? a : b;
}
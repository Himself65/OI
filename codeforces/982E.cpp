// #define LOCAL // For Windows
// #define TEST
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
int n, m, x, y, vx, vy;
int refx, refy;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll res = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return res;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &vx, &vy);
    if (vx == 0)
    {
        if (x == 0 || x == n)
        {
            if (vy == 1)
                printf("%d %d\n", x, m);
            else
                printf("%d %d\n", x, 0);
        }
        else
            puts("-1");
        return 0;
    }
    if (vy == 0)
    {
        if (y == 0 || y == m)
        {
            if (vx == 1)
                printf("%d %d\n", n, y);
            else
                printf("%d %d\n", 0, y);
        }
        else
            puts("-1");
        return 0;
    }
    if (vx == -1)
        refx = 1, x = n - x;
    if (vy == -1)
        refy = 1, y = m - y;
    //s'=(0,y-x)
    //an+(y-x)=bm => an+bm=(x-y)
    ll a, b, g;
    g = exgcd(n, m, a, b);
    if ((x - y) % g != 0)
    {
        puts("-1");
        return 0;
    }
    ll t = (x - y) / g;
    a *= t, b *= t;
    int _m = m / g, _n = n / g;
    ll _a = (a % _m + _m + _m - 1) % _m + 1, _b = -((x - y) - _a * n) / m;
    ll ansx = n, ansy = m;
    if (_a % 2 == 0)
        ansx = n - ansx;
    if (_b % 2 == 0)
        ansy = m - ansy;
    if (refx)
        ansx = n - ansx;
    if (refy)
        ansy = m - ansy;
    printf("%I64d %I64d", ansx, ansy);
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
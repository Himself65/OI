#define LOCAL
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
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

inline ll multi(ll a, ll b, ll m)
{
    ll r = 0;
    for (; b; a = (a << 1) % m, b >>= 1)
        if (b & 1)
            r = (r + a) % m;
    return r;
}
inline ll fast_exp(ll x, ll n, ll p)
{
    ll z = 1;
    for (ll y = x % p; n; y = y * y % p, n >>= 1)
        if (n & 1)
            z = z * y % p;
    return z;
}

ll bsgs(ll a, ll y, ll p)
{
    a %= p;
    y %= p;
    if (a == 0)
        return y > 1 ? -1 : y == 0 && p > 1;
    ll g, c = 0, q = 1;
    while ((g = gcd(a, p)) != 1)
    {
        if (y == 1)
            return c;
        if (y % g)
            return -1;
        ++c;
        y /= g;
        p /= g;
        q = a / g * q % p;
    }

    map<ll, ll> x;
    ll m = sqrt(p);
    for (ll i = 1, t = y * a % p; i <= m; ++i, t = t * a % p)
        x[t] = i;
    for (ll i = m, t = fast_exp(a, m, p); i - m < p - 1; i += m)
        if (q = q * t % p, x.count(q))
            return i - x[q] + c;
    return -1;
}
ll K, m;
int main()
{
    cin >> K >> m;
    K = (multi(K, 9, m) + 1) % m;
    ll ans = bsgs(10, K, m);
    cout << ans << endl;
#ifdef LOCAL
    system("pause");
#endif
}

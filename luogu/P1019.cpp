#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
inline ll min(ll a, ll b)
{
    return a < b ? a : b;
}
inline ll up(ll x, ll a)
{
    return (x / a) * a < x ? (x / a) + 1 : x / a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll p;
    cin >> p;
    ll i = 3;
    ll ans = 0x7f7f7f7f;
    while (i--)
    {
        ll num, v;
        cin >> num >> v;
        ll t = up(p, num) * v;
        ans = min(ans, t);
    }
    cout << ans;
    return 0;
}
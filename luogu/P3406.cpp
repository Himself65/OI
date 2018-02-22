#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
const int maxn = 100000 + 5;
ll n, m;
ll p[maxn];
ll val[maxn];
inline ll max(ll a, ll b)
{
    return a > b ? a : b;
}
inline ll min(ll a, ll b)
{
    return a < b ? a : b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> p[i];
    for (int i = 1; i < m; i++)
    {
        ll x = max(p[i], p[i + 1]);
        ll y = min(p[i], p[i + 1]);
        val[y]++;
        val[x]--;
    }
    for (int i = 1; i <= n; i++)
        val[i] += val[i - 1];
    long long ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ans += min(a * val[i], b * val[i] + c);
    }
    cout << ans;
    return 0;
}
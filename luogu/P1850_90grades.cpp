#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll t, k;
ll n, m;
ll c[2050][2050];
// c(m,n)=c(m-1,n-1)+c(m-1,n)
inline ll min(ll a, ll b)
{
    return a < b ? a : b;
}
int main()
{
    scanf("%lld%lld", &t, &k);
    // init
    for (ll i = 0; i <= 2010; i++)
        c[i][0] = 1;
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll mini = min(i, m);
            for (ll j = 1; j <= mini; j++)
            {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
                if (c[i][j] % k == 0)
                    ans++;
            }
        } // end - if
        printf("%lld\n", ans);
    }
    return 0;
}
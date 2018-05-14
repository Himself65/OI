#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll t, k;
ll n, m;
ll c[2050][2050];
ll s[2050][2050];
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
    for (ll i = 1; i <= 2010; i++)
        for (ll j = 1; j <= 2010; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
    for (ll i = 1; i <= 2010; i++)
        for (ll j = 1; j <= 2010; j++)
        {
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
            if (c[i][j] == 0 && j <= i)
                s[i][j]++; //前缀和
        }
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", s[n][m]);
    }
    return 0;
}
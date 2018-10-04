#include <cstdio>
const int N = 1e6 + 5, Mod = 998244353;
typedef long long ll;
inline ll in()
{
    register char c = getchar();
    register ll x = 0, f = 1;
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = (x << 1ll) + (x << 3ll) + c - '0';
    return x * f;
}
int main(int argc, char **argv)
{
    register int n = in();
    register ll ans = 0;
    for (register int i = 1; i <= n; ++i)
        ans = (ans + in()) % Mod;
    for (register int i = 1; i < n; ++i)
        ans = (ans << 1ll) % Mod;
    printf("%lld\n", ans);
}
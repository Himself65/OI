#define LOCAL // For Windows
#define TEST
// #define DATA
#define HAND
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
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD
{
ll x, a, b, c, d, n, tmp, tot[2];
inline int getnum(int zz)
{
    tmp = 0;
    while (zz)
        ++tmp, zz ^= (zz & (-zz));
    return tmp;
}
inline void solve()
{
    cin >> n >> a >> b >> c >> d >> x;
    a %= d, b %= d, c %= d, x %= d;
    for (int i = 1; i <= n; i++)
    {
        ++tot[getnum(x = ((a * x % d) * x % d + b * x % d + c) % d) & 1];
    }
    printf("%lld", tot[0] * tot[1]);
}
} // namespace BREAD
int main()
{
#ifdef LOCAL
#ifdef DATA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#endif
    BREAD::solve();
#ifdef TEST
#endif
#ifdef LOCAL
#ifdef HAND
    system("pause");
#endif
#endif
    return 0;
}

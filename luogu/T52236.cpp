#define LOCAL // For Windows
#define TEST
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
bool ok = true;
int n, m;
ll a[maxn];
ll b[maxn];
ll ans;
string cant = "tomarunjaneezo";
inline void solve()
{
    scanf("%d%d", &n, &m);
    for (register int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    for (register int k = 0; k < 32; k++)
    {
        for (register int i = 0; i < n; i++)
            b[i] = (a[i] >> k) & 1;
        ll maxd = 0, s = 0;
        for (register int i = 0; i < n; i++)
            if (!b[i])
            {
                ll cnt = 0, j = i + 2;
                while (b[(j % (n))] == 1)
                    cnt++, j += 2;
                maxd = max(maxd, cnt);
                s = s + cnt + 1;
            }
        if (s != n)
        {
            cout << cant;
            return;
        }
        else
            ans = max(ans, maxd);
    }
    cout << ans;
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
    // INIT_CIN;
    BREAD::solve();
#ifdef LOCAL
#ifdef HAND
    system("pause");
#endif
#endif
    return 0;
}

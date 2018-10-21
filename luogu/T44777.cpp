#define LOCAL // For Windows
#define TEST
#define DATA
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
const int maxn = 1e3 + 5;
const int maxv = 2e4 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
const int MOD = 998244353;
int n, m = -1;
int a[maxn], f[maxv], ans;
int main()
{
#ifdef LOCAL
#ifdef DATA
    freopen("in3.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);
#endif
#endif
    // INIT_CIN;
    scanf("%d", &n);
    ans = n;
    for (register int i = 1; i <= n; i++)
        scanf("%d", a + i), m = max(m, *(a + i));
    for (register int i = -m; i <= m; i++)
    {
        for (register int j = 1; j <= n; j++)
            f[a[j]] = 0;
        for (register int j = 1; j <= n; j++)
        {
            int &t = f[a[j]];
            int d = a[j] - i;
            if (d >= 0 && d <= m)
                ans = (ans + f[d]) % MOD;
            if (d >= 0 && d <= m)
                t = (f[d] + t + 1) % MOD;
            else
                t = (t + 1) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}

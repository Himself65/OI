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
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e6 + 5;
int n;
ll a[maxn], q[maxn], s[maxn];
inline ll max(ll a, ll b) { return a > b ? a : b; }
int h = 1, t = 0; // head / end
int ans = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n - 1; i++)
        a[i + n] = a[i];
    for (int i = 1; i <= 2 * n - 1; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        while (h <= t && max(i - n + 1, 1) > q[h])
            h++;
        while (h <= t && s[i] <= s[q[t]])
            t--;
        q[++t] = i;
        if (i - n + 1 >= 1 && s[q[t]] - s[i - n] >= 0)
            ans++;
    }
    cout << ans << endl;
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
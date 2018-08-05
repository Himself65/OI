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
const int maxn = 5e+4 + 5;
int n, m, dist;
ll a[maxn];
ll ans = 0;
inline ll max(ll a, ll b) { return a > b ? a : b; }
inline ll min(ll a, ll b) { return a < b ? a : b; }
inline bool check(int p)
{
    int tot = 0, i = 0, now = 0;
    while (i < n + 1)
    {
        i++;
        if (a[i] - a[now] < p)
            tot++;
        else
            now = i;
    }
    if (tot > m)
        return false;
    else
        return true;
}
int main()
{
    scanf("%d%d%d", &dist, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    a[n + 1] = dist;
    ll l = 1, r = dist, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            ans = mid,
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%lld", ans);
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
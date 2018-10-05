#define LOCAL // For Windows
#define TEST
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
const int maxn = 1e5 + 5;
int T;
ll n, m, p;
// a[i] = (p-p/i) * a[p%i]
ll a[maxn], b[maxn];
/**
 * 卢卡斯定理
 * lucas(n,m,p) = c(n%p, m%p) * lucas(n/p, m/p, p)
 * p为质数
 * C(n,m) = n!/(m!*(n-m)!)
 */
inline ll lucas(ll x, ll y)
{
    if (x < y)  // 不存在
        return 0;
    else if (x < p)
        return b[x] * a[y] * a[x - y] % p;
    else
        return lucas(x / p, y / p) * lucas(x % p, y % p) % p;
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> p;
        a[0] = a[1] = b[0] = b[1] = 1;
        for (int i = 2; i <= n + m; i++)
            b[i] = b[i - 1] * i % p;
        for (int i = 2; i <= n + m; i++)
            a[i] = (p - p / i) * a[p % i] % p;
        for (int i = 2; i <= n + m; i++)
            a[i] = a[i - 1] * a[i] % p;
        cout << lucas(n + m, m) << endl;
    }
#ifdef TEST
#endif
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
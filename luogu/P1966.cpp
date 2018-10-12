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
// #define LOWBIT(x) ((x) & (-x))
const int maxn = 1e6 + 5;
int n;
int a[maxn], b[maxn], c[maxn], d[maxn], q[maxn], te[maxn];
const int MOD = 99999997;
// -- 树状数组 --
// 修改
inline int lowbit(int x)
{
    return x & (-x);
}
inline void modify(int x, int v)
{
    while (x <= n)
    {
        te[x] += v;
        x += lowbit(x);
    }
}
// 查询
inline int query(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += te[x];
        x -= lowbit(x);
    }
    return res;
}
// -- 树状数组 --
inline bool cmp1(int i, int j) { return a[i] < a[j]; }
inline bool cmp2(int i, int j) { return b[i] < b[j]; }
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], c[i] = i, d[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(c + 1, c + 1 + n, cmp1);
    sort(d + 1, d + 1 + n, cmp2);
    memset(te, 0, sizeof(te));
    for (int i = 1; i <= n; i++)
        q[c[i]] = d[i];
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        ans += query(q[i] - 1);
        modify(q[i], 1);
        if (ans >= MOD)
            ans -= MOD;
    }
    printf("%d\n", (ans % MOD + MOD) % MOD);
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
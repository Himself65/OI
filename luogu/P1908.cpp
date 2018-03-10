#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
const int maxn = 40000 + 5;
int n, x;
int f[maxn];
int a[maxn];
int d[maxn];
int c[maxn];
#define lowbit(x) (x & -(x))
inline void set_value(int x, int v)
{
    while (x <= n)
    {
        f[x] += v;
        x += lowbit(x);
    }
}

inline int find_value(int x)
{
    int ans = 0;
    while (x)
    {
        ans += f[x];
        x -= lowbit(x);
    }
    return ans;
}

inline bool cop(int _x, int _y) { return a[_x] < a[_y]; }

int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = i;
    }
    sort(d + 1, d + 1 + n, cop);
    for (int i = 1; i <= n; i++)
    {
        a[d[i]] = i;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (c[i - 1] > a[i - 1])
            c[i] = c[i - 1];
        else
            c[i] = a[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] + 1 <= c[i])
            ans += find_value(c[i]) - find_value(a[i]);
        set_value(a[i], 1);
    }
    cout << ans;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
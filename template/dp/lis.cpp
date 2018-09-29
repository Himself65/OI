#define LOCAL
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int n = 8;
int a[maxn] = {0, 3, 2, 4, 1, 5, 6, 2, 1};
int f1[maxn];
inline int max(int a, int b) { return a > b ? a : b; }
/**
 * 设 d(i) 为以i为结尾的最长上升子序列的长度
 * 则 d(i) = max{0, d(j) | j<i, a[j]<a[i] } + 1
 * cout << max{d(i)}
 */
inline void solve1()
{
    // O(n^2)
    int ans = -1;
    for (int i = 1; i <= n; i++)
        f1[i] = 1; // 注意初始化
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f1[i] = max(f1[i], f1[j] + 1);
    for (int i = 1; i <= n; i++)
        ans = max(ans, f1[i]);
    cout << ans << endl;
}
const int INF = 0x7f7f7f7f;
int f2[maxn], g[maxn], d[maxn];
inline void solve2()
{
    // O(nlogn)
    int ans = -1;
    for (int i = 1; i <= n; i++)
        g[i] = INF;
    for (int i = 1; i <= n; i++)
    {
        int k = lower_bound(g + 1, g + n + 1, a[i]) - g;
        d[i] = k;
        g[k] = a[i];
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
}
int main()
{
    solve1();
    solve2();
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

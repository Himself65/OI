#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 500 + 5;
int n;
int s[maxn], a[maxn], f1[maxn][maxn], f2[maxn][maxn];
int mi = 0x7f7f7f7f;
int mx = -1;
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline int min(int a, int b)
{
    return a < b ? a : b;
}
int dfs_max(int l, int r)
{
    if (f1[l][r])
        return f1[l][r];
    if (l == r)
        return 0;
    int res = 0;
    for (int k = l; k < r; k++)
        res = max(res, dfs_max(l, k) + dfs_max(k + 1, r) + s[r] - s[l - 1]);
    return f1[l][r] = res;
}
int dfs_min(int l, int r)
{
    if (f2[l][r])
        return f2[l][r];
    if (l == r)
        return 0;
    int res = 0x3f3f3f3f;
    for (int k = l; k < r; k++)
        res = min(res, dfs_min(l, k) + dfs_min(k + 1, r) + s[r] - s[l - 1]);
    return f2[l][r] = res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n << 1; i++)
        s[i] = s[i - 1] + a[i];
    dfs_max(1, n << 1);
    dfs_min(1, n << 1);
    for (int i = 1; i <= n; i++)
    {
        mi = min(mi, dfs_min(i, n + i - 1));
        mx = max(mx, dfs_max(i, n + i - 1));
    }
    printf("%d\n%d", mi, mx);
    return 0;
}
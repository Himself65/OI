#include<iostream>
#include<cstdio>
#include<cstring>
#define rint register int
using namespace std;
int n, m, ans = 1000000007, a[6001], b[6001], c[6001], f[2][30001], now, pre;

inline int max(int x,int y)
{
    if (x > y)
        return x;
    return y;
}
inline int min(int x,int y)
{
    if (x < y)
        return x;
    return y;
}
int main()
{
    scanf("%d", &n);
    memset(f, 127, sizeof(f));
    f[1][0] = 0;
    pre = 1;
    for (rint i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        now = pre ^ 1;
        m += max(a[i], c[i]);
        for (rint j = m; j >= 0; j--)
        {
            if (b[i]!=0)
                f[now][j] = f[pre][j] + b[i];
            if (j>=a[i] && a[i]!=0)
                f[now][j] = min(f[now][j], f[pre][j - a[i]] + a[i]);
            if (j>=c[i] && c[i]!=0)
                f[now][j] = min(f[now][j], f[pre][j - c[i]] + 2 * c[i]);
        }
        memset(f[pre], 127, sizeof(f[pre]));
        pre ^= 1;
    }
    for (rint i=m;i>=0;i--)
        ans = min(ans, max(i, f[now][i] - i));
    printf("%d", ans);
    return 0;
}
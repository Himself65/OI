#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 200000 + 5;
int n, a[maxn], f[maxn];
int ans = 0x3f3f3f3f;
inline void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i;
}

inline int father(int x)
{
    int lt = f[x];
    if (f[x] != x)                          // 如果不是自己不是根
        f[x] = father(f[x]), a[x] += a[lt]; // 那么fx找父亲，然后距离加等于原先的父亲
    return f[x];
}

inline void add(int x, int y)
{
    int fatherx = father(x);
    int fathery = father(y);
    if (fatherx == fathery)
        ans = min(ans, a[x] + a[y] + 1);
    else
        f[fatherx] = fathery, a[x] = a[y] + 1;
}
int main()
{
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        add(i, t);
    }
    printf("%d", ans);
    return 0;
}
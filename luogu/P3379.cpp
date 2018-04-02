#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 500000 + 5;
int head[maxn], d[maxn], f[maxn][21], lg[maxn];
int n, m, s, cnt, a, b;
struct Node
{
    int v, next;
} edge[maxn << 2];
inline void add(int a, int b)
{
    edge[++cnt].v = b;
    edge[cnt].next = head[a];
    head[a] = cnt;
}
inline void dfs(int u, int fa)
{
    d[u] = d[fa] + 1;
    f[u][0] = fa;
    for (register int i = 1; (1 << i) <= d[u]; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (register int i = head[u]; i; i = edge[i].next)
        if (edge[i].v != fa)
            dfs(edge[i].v, u);
}
inline int lca(int a, int b)
{
    if (d[a] < d[b])
        swap(a, b);
    while (d[a] > d[b])
        a = f[a][lg[d[a] - d[b]] - 1];
    if (a == b)
        return a;
    for (register int k = lg[d[a]]; k >= 0; k--)
        if (f[a][k] != f[b][k])
            a = f[a][k], b = f[b][k];
    return f[a][0];
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; i++)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    for (register int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(s, 0);
    for (register int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}

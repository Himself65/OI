#define inf 336860180
#define S (1 << 20) + 1
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int cango[21][S];
int vis[S], f[S], doit[S], nu[S];
int n, m, alsta;
int do_it(int sta)
{
    int z = sta;
    while (z)
    {
        nu[sta] += (z & 1);
        z >>= 1;
    }
}
int dfs(int sta)
{
    if (vis[sta])
        return f[sta];
    vis[sta] = 1;
    f[sta] = inf;
    for (int i = 1; i <= n; ++i)
    {
        int tosta = sta ^ (1 << i - 1);
        if (sta & (1 << i - 1) && cango[i][tosta] != inf)
        {
            int get = dfs(tosta) + cango[i][tosta];
            if (f[sta] > get)
            {
                f[sta] = get;
                doit[sta] = i;
            }
        }
    }
    return f[sta];
}
void putit(int sta)
{
    if (sta == 10)
    {
        printf("%d\n", doit[sta]);
        int zz;
        cin >> zz;
    }
    if (!sta)
        return;
    printf("%d\n", doit[sta]);
    putit(sta ^ (1 << doit[sta] - 1));
}
int main()
{
    memset(cango, 20, sizeof(cango));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, sta, l;
        scanf("%d%d%d%d", &u, &v, &sta, &l);
        cango[u][sta | (1 << v - 1)] = min(cango[u][sta | (1 << v - 1)], l);
        cango[v][sta | (1 << u - 1)] = min(cango[v][sta | (1 << u - 1)], l);
    }
    alsta = (1 << n) - 1;
    for (int i = 0; i <= alsta; ++i)
        for (int j = i; j; j = i & (j - 1))
        {
            if (nu[i] - nu[j] > 1)
                break;
            for (int k = 1; k <= n; ++k)
                cango[k][i] = min(cango[k][i], cango[k][j]);
        }
    for (int i = 1; i <= n; ++i)
        vis[1 << i - 1] = 1, doit[1 << i - 1] = i;
    dfs(alsta);
    if (f[alsta] == inf)
        f[alsta] = -1;
    printf("%d\n", f[alsta]);
    return 0;
}
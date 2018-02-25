// #include <algorithm>
// #include <cstdio>
// #include <cstdlib>
// #include <vector>
// #define maxn 1005
// using namespace std;
// int n, m, a1, a2, c1, c2, S[2 * maxn], c = 0;
// vector<int> geo[2 * maxn];
// bool vis[2 * maxn];
// bool dfs(int x)
// {
//     if (vis[x])
//         return true;
//     if (vis[x ^ 1])
//         return false;
//     vis[x] = 1;
//     S[c++] = x;
//     for (int i = 0; i < geo[x].size(); i++)
//     {
//         int op = geo[x][i];
//         if (!dfs(op))
//             return false;
//     }
//     return true;
// }
// bool Bi_SAT()
// {
//     for (int i = 0; i < 2 * n; i += 2)
//         if (!vis[i] && !vis[i + 1])
//         {
//             c = 0;
//             if (!dfs(i))
//             {
//                 while (c > 0)
//                 {
//                     vis[S[--c]] = 0;
//                 }
//                 if (!dfs(i + 1))
//                     return false;
//             }
//         }
//     return true;
// }
// void recover()
// {
//     for (int i = 0; i < 2 * n; i++)
//         vis[i] = 0;
//     for (int i = 0; i < 2 * n; i++)
//         geo[i].clear();
//     return;
// }
// int main()
// {
//     while (scanf("%d%d", &n, &m) == 2)
//     {
//         for (int i = 0; i < m; i++)
//         {
//             scanf("%d%d%d%d", &a1, &a2, &c1, &c2);
//             geo[(a1 << 1) + c1].push_back((a2 << 1) + (c2 ^ 1));
//             geo[(a2 << 1) + c2].push_back((a1 << 1) + (c1 ^ 1));
//         }
//         if (Bi_SAT())
//             printf("YES\n");
//         else
//             printf("NO\n");
//         recover();
//     }
//     return 0;
// }
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline int read()
{
    int res = 0;
    bool bo = 0;
    char c;
    while (((c = getchar()) < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        bo = 1;
    else
        res = c - 48;
    while ((c = getchar()) >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c - 48);
    return bo ? ~res + 1 : res;
}
inline char get()
{
    char c;
    while ((c = getchar()) != 'A' && c != 'B' && c != 'C')
        ;
    return c;
}
const int N = 2e5 + 5;
int n, d, m, a1[N], b1[N], ecnt, nxt[N], adj[N], go[N], dfn[N], low[N],
    times, num, bel[N], top, stk[N], cyx[N];
char s[N], a2[N], b2[N], orz[N];
bool ins[N], flag;
void add_edge(int u, int v)
{
    nxt[++ecnt] = adj[u];
    adj[u] = ecnt;
    go[ecnt] = v;
}
int neg(int x) { return x > n ? x - n : x + n; }
int tran(int x, char c)
{
    if (s[x] == 'a')
        return c == 'B' ? x : x + n;
    if (s[x] == 'b' || s[x] == 'c')
        return c == 'A' ? x : x + n;
    if (c == 'C')
        return x + n;
    return x;
}
void Tarjan(int u)
{
    dfn[u] = low[u] = ++times;
    ins[stk[++top] = u] = 1;
    for (int e = adj[u], v; e; e = nxt[e])
        if (!dfn[v = go[e]])
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
            low[u] = min(low[u], dfn[v]);
    if (dfn[u] == low[u])
    {
        int v;
        bel[u] = ++num;
        ins[u] = 0;
        while (v = stk[top--], v != u)
            bel[v] = num, ins[v] = 0;
    }
}
bool solve()
{
    int i;
    ecnt = times = num = 0;
    for (i = 1; i <= (n << 1); i++)
        bel[i] = adj[i] = dfn[i] = 0;
    for (i = 1; i <= m; i++)
        if (s[a1[i]] != 'x' && s[b1[i]] != 'x')
        {
            if (a2[i] == s[a1[i]] - 32)
                continue;
            int u = tran(a1[i], a2[i]), v;
            if (b2[i] == s[b1[i]] - 32)
            {
                add_edge(u, neg(u));
                continue;
            }
            v = tran(b1[i], b2[i]);
            add_edge(u, v);
            add_edge(neg(v), neg(u));
        }
        else
        {
            char o = s[a1[i]], p = s[b1[i]];
            int u, v, x = cyx[a1[i]], y = cyx[b1[i]];
            if (o == 'x' && p == 'x')
            {
                if (a2[i] == orz[x])
                    continue;
                u = tran(a1[i], a2[i]), v;
                if (b2[i] == orz[y])
                {
                    add_edge(u, neg(u));
                    continue;
                }
                v = tran(b1[i], b2[i]);
                add_edge(u, v);
                add_edge(neg(v), neg(u));
            }
            else if (o == 'x' && p != 'x')
            {
                if (a2[i] == orz[x])
                    continue;
                u = tran(a1[i], a2[i]), v;
                if (b2[i] == s[b1[i]] - 32)
                {
                    add_edge(u, neg(u));
                    continue;
                }
                v = tran(b1[i], b2[i]);
                add_edge(u, v);
                add_edge(neg(v), neg(u));
            }
            else
            {
                if (a2[i] == s[a1[i]] - 32)
                    continue;
                u = tran(a1[i], a2[i]), v;
                if (b2[i] == orz[y])
                {
                    add_edge(u, neg(u));
                    continue;
                }
                v = tran(b1[i], b2[i]);
                add_edge(u, v);
                add_edge(neg(v), neg(u));
            }
        }
    for (i = 1; i <= (n << 1); i++)
        if (!dfn[i])
            Tarjan(i);
    for (i = 1; i <= n; i++)
        if (bel[i] == bel[i + n])
            return 0;
    for (i = 1; i <= n; i++)
    {
        if (bel[i] < bel[i + n])
        {
            if (s[i] == 'a')
                putchar('B');
            else if (s[i] == 'b' || s[i] == 'C')
                putchar('A');
            else if (orz[cyx[i]] == 'A')
                putchar('B');
            else
                putchar('A');
        }
        else
        {
            if (s[i] == 'a' || s[i] == 'b')
                putchar('C');
            else if (s[i] == 'c')
                putchar('B');
            else if (orz[cyx[i]] == 'A')
                putchar('C');
            else
                putchar('B');
        }
    }
    return 1;
}
void dfs(int dep)
{
    if (dep > d)
    {
        if (!flag)
            flag = solve();
        if (flag)
            exit(0);
        return;
    }
    orz[dep] = 'A';
    dfs(dep + 1);
    orz[dep] = 'B';
    dfs(dep + 1);
}
int main()
{
    int i;
    n = read();
    read();
    scanf("%s", s + 1);
    m = read();
    for (i = 1; i <= n; i++)
        if (s[i] == 'x')
            cyx[i] = ++d;
    for (i = 1; i <= m; i++)
        a1[i] = read(), a2[i] = get(),
        b1[i] = read(), b2[i] = get();
    dfs(1);
    if (!flag)
        puts("-1");
    return 0;
}
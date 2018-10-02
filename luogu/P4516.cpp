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
const int maxk = 100 + 5;
const int mod = 1000000007;
int n, k;
int fa[maxn], sz[maxn], f[maxn][maxk][2][2], g[maxk][2][2];
vector<int> G[maxn];
inline void add_v(int x, int y)
{
    G[x].push_back(y);
}
inline int get_mod(ll a, ll b) { return (a + ((int)(b % mod))) % mod; }
inline int min(int a, int b) { return a < b ? a : b; }
// 当前为 u
// 父亲为 fa
inline void dfs(int u, int fa)
{
    sz[u] = 1;
    f[u][0][0][0] = f[u][1][1][0] = 1;
    // 枚举子树
    for (int ct = 0; ct < G[u].size(); ct++)
    {
        int v = G[u][ct];
        // not father
        if (v == fa)
            continue;
        dfs(v, u);
        for (int i = 0; i <= min(sz[u], k); i++)
        {
            g[i][0][0] = f[u][i][0][0], f[u][i][0][0] = 0;
            g[i][0][1] = f[u][i][0][1], f[u][i][0][1] = 0;
            g[i][1][0] = f[u][i][1][0], f[u][i][1][0] = 0;
            g[i][1][1] = f[u][i][1][1], f[u][i][1][1] = 0;
        }
        for (int i = 0; i <= min(sz[u], k); i++)
            for (int j = 0; j <= min(sz[v], k - i); j++)
            {
                f[u][i + j][0][0] = get_mod(f[u][i + j][0][0], (ll)g[i][0][0] * (ll)f[v][j][0][1]);
                f[u][i + j][1][0] = get_mod(f[u][i + j][1][0], (ll)g[i][1][0] * (ll)(f[v][j][0][0] + f[v][j][0][1]));
                f[u][i + j][0][1] = get_mod(f[u][i + j][0][1], (ll)g[i][0][0] * (ll)f[v][j][1][1] + (ll)g[i][0][1] * (ll)(f[v][j][0][1] + f[v][j][1][1]));
                f[u][i + j][1][1] = get_mod(f[u][i + j][1][1], (ll)g[i][1][0] * (ll)(f[v][j][1][1] + f[v][j][1][0]) + (ll)g[i][1][1] * (ll)((ll)(f[v][j][0][0] + f[v][j][0][1]) + (ll)(f[v][j][1][1] + f[v][j][1][0])));
            }
        sz[u] += sz[v];
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add_v(a, b);
        add_v(b, a);
    }
    dfs(1, 0);
    printf("%d\n", (f[1][k][1][1] + f[1][k][0][1]) % mod);
#ifdef TEST
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < G[i].size(); j++)
        {
            printf("%d to %d\n", i, G[i][j]);
        }
    }
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
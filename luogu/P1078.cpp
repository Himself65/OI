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
const int INF = 0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxm = 1e4 + 5;
struct Node
{
    int to, val, next;
} edge[maxm];
int n, k, m, s, t;
int c[maxn];
int a[maxn][maxn];
int head[maxn], tot;
inline void add(int from, int to, int val)
{
    edge[++tot].to = to;
    edge[tot].val = val;
    edge[tot].next = head[from];
    head[from] = tot;
}
int ans, dist[maxn];
bool vis[maxn], learned[maxn];
inline int min(int a, int b) { return a < b ? a : b; }
inline bool exclude(int x, int y) { return a[c[x]][c[y]]; }
inline void spfa()
{
    memset(dist, INF, sizeof(dist));
    dist[t] = 0;
    queue<int> q;
    q.push(t), vis[t] = learned[c[t]] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        vis[p] = learned[c[p]] = true;
#ifdef TEST
        printf("now at point: %d\n", p);
#endif
        for (int i = head[p]; i; i = edge[i].next)
        {
            Node &t = edge[i];
#ifdef TEST
            printf("from %d to %d\n", p, t.to);
#endif
            if (dist[t.to] > dist[p] + t.val)
            {
                dist[t.to] = dist[p] + t.val;
                if (!vis[t.to] && !exclude(p, t.to) && !learned[c[t.to]])
                    q.push(t.to);
            }
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d%d%d", &n, &k, &m, &s, &t);
    for (register int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (register int i = 1; i <= k; i++)
        for (register int j = 1; j <= k; j++)
            scanf("%d", &a[i][j]);
    for (register int i = 1; i <= m; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add(u, v, d), add(v, u, d);
    }
    spfa();
    cout << (dist[s] >= INF ? -1 : dist[s]);
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
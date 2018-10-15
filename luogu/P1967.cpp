#define LOCAL // For Windows
#define TEST
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 5e5 + 5;
int n, m, que_num;
struct EDGE
{
    int x, y, v;
} edge[maxm];
struct NODE
{
    int y, val, next;
} max_edge[maxm];
void print(int x)
{
    int l = 0;
    char ch[64];
    if (!x)
    {
        putchar('0');
        return;
    }
    if (x < 0)
        putchar('-'), x = -x;
    while (x)
        ch[++l] = x % 10 + '0', x /= 10;
    for (int i = l; i; i--)
        putchar(ch[i]);
}
inline void read(int &x)
{
    int f = 1;
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}
namespace BREAD
{
int tot;
int father[maxn], head[maxn], deep[maxn], p[maxn][20 + 5], w[maxn][20 + 5];
inline bool cmp(const EDGE &a, const EDGE &b) { return a.v > b.v; }
inline void init(int x = maxn)
{
    for (register int i = 1; i <= x; i++)
        father[i] = i;
}
inline int find(int x)
{
    if (x == father[x])
        return x;
    else
        return father[x] = find(father[x]);
}
inline void merge(int x, int y)
{
    int fatherx = find(x);
    int fathery = find(y);
    if (fatherx == fathery)
        return;
    father[fatherx] = fathery;
}
inline bool same(int x, int y)
{
    return find(x) == find(y);
}
// end
inline void add_edge(int x, int y, int val)
{
    max_edge[++tot].val = val;
    max_edge[tot].y = y;
    max_edge[tot].next = head[x];
    head[x] = tot;
}
// kruskal 求最大生成树
// 原理和最小生成树一样
// 只不过排序的比较函数变了一下
inline void kruskal()
{
    sort(edge + 1, edge + 1 + m, cmp);
    int ct = 0;
    for (register int i = 1; i <= m; i++)
    {
        EDGE &t = edge[i];
        if (!same(t.x, t.y))
        {
            merge(t.x, t.y);
            add_edge(t.x, t.y, t.v);
            add_edge(t.y, t.x, t.v);
            if (++ct == n) // 全部点已经构建完毕，无需继续
                break;
        }
    }
}
inline void dfs(int x)
{
    for (register int i = head[x]; i; i = max_edge[i].next)
    {
        int y = max_edge[i].y;
        if (deep[y] == 0)
        {
            deep[y] = deep[x] + 1;
            p[y][0] = x;
            w[y][0] = max_edge[i].val;
            dfs(y);
        }
    }
}
inline void solve()
{
    for (register int i = 1; i <= n; i++)
    {
        if (deep[i] == 0)
        {
            deep[i] = 1;
            p[i][0] = 0;
            dfs(i);
        }
    }
    dfs(1);
    for (register int i = 1; i <= 20; i++)
    {
        for (register int x = 1; x <= n; x++)
        {
            p[x][i] = p[p[x][i - 1]][i - 1];
            w[x][i] = min(w[x][i - 1], w[p[x][i - 1]][i - 1]);
        }
    }
}
inline int lca(int x, int y)
{
    int ans = INF;
    if (deep[x] < deep[y])
        swap(x, y);
    for (register int i = 20; i >= 0; i--)
        if (deep[p[x][i]] >= deep[y])
            ans = min(ans, w[x][i]), x = p[x][i];
    if (x == y)
        return ans;
    for (register int i = 20; i >= 0; i--)
        if (p[x][i] != p[y][i])
            ans = min(ans, min(w[x][i], w[y][i])), x = p[x][i], y = p[y][i];
    ans = min(ans, min(w[x][0], w[y][0]));
    return ans;
}
} // namespace BREAD

int main()
{
    read(n), read(m);
    for (register int i = 1; i <= m; i++)
    {
        EDGE &t = edge[i];
        read(t.x), read(t.y), read(t.v);
    }
    BREAD::init();
    BREAD::kruskal();
    BREAD::solve();
    read(que_num);
    for (register int i = 1; i <= que_num; i++)
    {
        register int x, y;
        read(x), read(y);
        if (!BREAD::same(x, y))
            print(-1);
        else
            print(BREAD::lca(x, y));
        putchar('\n');
    }
#ifdef TEST
    // printf("The front row sells a variety of small breads\n");
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
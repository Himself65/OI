// 第二次写模版
#include <algorithm>
#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;
const int maxm = 200000 + 5;
const int maxn = 5000 + 5;
int n, m;
int x, y, z;
struct Edge
{
    int from, to, value;
} edge[maxm];
inline bool cop(Edge &a, Edge &b)
{
    return a.value < b.value;
}
int tree[maxn];
int high[maxn];
inline void init()
{
    for (int i = 0; i <= maxn; i++)
        tree[i] = i;
}
inline int find(int x)
{
    if (tree[x] == x)
        return x;
    return tree[x] = find(tree[x]);
}
inline bool same(int a, int b)
{
    return find(a) == find(b);
}
inline void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        tree[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        edge[i].value = z;
        edge[i].from = x;
        edge[i].to = y;
    }
    sort(edge + 1, edge + 1 + m, cop);
    init();
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        Edge &x = edge[i];
        if (!same(x.from, x.to))
        {
            unite(x.from, x.to);
            ans += x.value;
        }
    }
    cout << ans << endl;
    return 0;
}
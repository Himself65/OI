#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5000 + 5;
int heap[maxn + 1];
int sz = 0;
int n, m;

struct Node
{
    int x, y, cost;
} edge[200000];

int parent[maxn + 1];
int high[maxn + 1];
inline void init()
{
    for (int i = 0; i <= maxn; i++)
        parent[i] = i;
}

inline int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

inline void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (high[a] < high[b])
    {
        parent[a] = b;
    }
    else
    {
        parent[b] = a;
        if (high[a] == high[b])
            high[a]++;
    }
}

inline bool same(int x, int y)
{
    return find(x) == find(y);
}

inline bool compare(Node &a, Node &b)
{
    return a.cost < b.cost;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> edge[i].x;
        cin >> edge[i].y;
        cin >> edge[i].cost;
    }
    sort(edge, edge + m, compare);
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        Node e = edge[i];
        if (!same(e.x, e.y))
        {
            ans += e.cost;
            unite(e.x, e.y);
        }
    }
    cout << ans;
    return 0;
}
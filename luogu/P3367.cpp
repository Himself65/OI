#include <cstdio>
#include <iostream>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 10000 + 5;
int parent[maxn];
int high[maxn];
int n, m;
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i, high[i] = i;
}

inline int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

inline void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (high[x] < high[y])
        parent[x] = parent[y];
    else
    {
        parent[y] = x;
        if (high[x] == high[y])
            high[x]++;
    }
}

inline bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m;
    init(n);
    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            unite(a, b);
        else
            cout << (same(a, b) ? "Y" : "N") << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
const int maxn = 1000+5;
struct DisjointSets
{
    int par[maxn];
    int rank[maxn];

    DisjointSets() { init(maxn); }
    DisjointSets(int n) { init(n); }

    inline void init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = i;
        }
        return;
    }
    inline int find(int x)
    {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);   //路径压缩
    }

    inline void unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (rank[x] < rank[y])
            par[x] = y;
        else
        {
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    inline bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    DisjointSets ds;
    ds.init(6);
    ds.unite(1, 2);
    ds.unite(2, 3);
    ds.unite(3, 5);
    cout << ds.same(4, 5) << endl
         << ds.same(1, 5) << endl;
    return 0;
}
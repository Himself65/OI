#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1000 + 5;
int a[maxn][maxn];
int res[maxn][maxn];
int lin[1000001][2];
int n, m, pl;
int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y)
{
    pl++;
    lin[pl][0] = x;
    lin[pl][1] = y;
    res[x][y] = 1;
    for (int i = 0; i <= 3; i++)
    {
        int u = x + mv[i][0];
        int v = y + mv[i][1];
        if (u < 1 || u > n || v < 1 || v > n)
            continue;
        else if (res[u][v] > 0)
            continue;
        else if (a[u][v] == a[x][y])
            continue;
        dfs(u, v);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%1d", &a[i][j]);
    while (m--)
    {
        pl = 0;
        int x, y;
        cin >> x >> y;
        if (res[x][y] > 0)
            cout << res[x][y] << endl;
        else
        {
            dfs(x, y);
            for (int j = 1; j <= pl; j++)
                res[lin[j][0]][lin[j][1]] = pl;
            cout << pl << endl;
        }
    }
    return 0;
}
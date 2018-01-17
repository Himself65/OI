#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 450;
bool vis[maxn][maxn];
struct Node
{
    int x, y;
};
pair<Node, ll> map[maxn][maxn];
int n, m, x0, y0;
const int mx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int my[] = {2, -2, 2, -2, 1, -1, 1, -1};
inline void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            map[i][j].first.x = i;
            map[i][j].first.y = j;
            map[i][j].second = -1;
        }
    queue<pair<Node, ll> > q;
    map[x0][y0].second = 0;
    q.push(map[x0][y0]);
    while (!q.empty())
    {
        pair<Node, ll> &t = q.front();
        vis[t.first.x][t.first.y] = true;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            pair<Node, ll> &p = map[t.first.x + mx[i]][t.first.y + my[i]];
            if (p.first.x > n || p.first.x < 1 || p.first.y < 1 || p.first.y > m)
                continue;
            if (vis[p.first.x][p.first.y])
                continue;
            p.second = t.second + 1;
            vis[p.first.x][p.first.y] = true;
            q.push(p);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%-5lld", map[i][j].second);
        }
        printf("\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x0 >> y0;
    solve();
    return 0;
}
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1005;
const int mx[] = {1, 0, 0, -1};
const int my[] = {0, 1, -1, 0};
struct Node
{
    int x, y;
    bool v;
    Node() : v(false) {}
};
Node map[maxn][maxn];
bool vis[maxn][maxn];
int mem[maxn][maxn];
int n, m;
inline void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j].x = i;
            map[i][j].y = j;
        }
    }
    while (m--)
    {
        memset(vis, false, sizeof(vis));
        int x0, y0;
        cin >> x0 >> y0;
        if(mem[x0][y0]>0)
        {
            cout << mem[x0][y0] << endl;
            continue;
        }
        int ans = 0;
        vis[x0][y0] = true;
        queue<Node> q;
        q.push(map[x0][y0]);
        while (!q.empty())
        {
            Node &node = q.front();
            q.pop();
            ans++;
            for (int i = 0; i < 4; i++)
            {
                Node &t = map[node.x + mx[i]][node.y + my[i]];
                if (t.x < 1 || t.x > n || t.y < 1 || t.y > n)
                    continue;
                if ((t.v ^ node.v) == 0)
                    continue;
                if (vis[t.x][t.y])
                    continue;
                vis[t.x][t.y] = true;
                q.push(t);
            }
        }
        cout << ans << endl;
        mem[x0][y0] = ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            map[i][j].v = ch - '0';
        }
    solve();
    return 0;
}
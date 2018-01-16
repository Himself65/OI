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
#define Left_Child(x) (x << 1)
#define Right_Child(x) (x << 1 | 1)
#define Mid(l, r) ((l + r) / 2)
#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 35;
int n;
int a[maxn][maxn];
int b[maxn][maxn];
bool vis[maxn][maxn];
int mv[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y)
{
    if (x > n || x < 1 || y > n || y < 1 || a[x][y] != 0)
        return;
    a[x][y] = 1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

inline void solve()
{
    // 暴力搜索边框
    for (int i = 1; i <= n; i++)
    {
        if (a[i][1] != 1)
            dfs(i, 1);
        if (a[i][n] != 1)
            dfs(i, n);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[1][i] != 1)
            dfs(1, i);
        if (a[n][i] != 1)
            dfs(n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] == -1)
                cout << "1 ";
            else if (a[i][j] == 0)
                cout << "2 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                b[i][j] = -1;
        }
    solve();
    return 0;
}
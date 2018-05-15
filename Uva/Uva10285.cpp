#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
const int maxn = 100 + 5;
int r, c, t;
int a[maxn][maxn], f[maxn][maxn];
string s;
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
inline int max(int a, int b) { return a > b ? a : b; }
int solve(int x, int y)
{
    if (x < 1 || x > r || y < 1 || y > c)
        return 0;
    if (f[x][y])
        return f[x][y];
    f[x][y] = 1;
    for (int i = 0; i < 4; i++)
        if (a[x][y] > a[x + mx[i]][y + my[i]])
            f[x][y] = max(f[x][y], solve(x + mx[i], y + my[i]) + 1);
    return f[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        cin >> s >> r >> c;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> a[i][j];
        int ans = 1;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                ans = max(ans, solve(i, j));
        cout << s << ": " << ans << endl;
    }
    return 0;
}
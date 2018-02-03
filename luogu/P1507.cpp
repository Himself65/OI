#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 200 + 5;
int n, m;
int a[maxn][maxn];
int f[maxn][maxn];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline void solve()
{
    int px = m;
    int py = n / 2 + 1;
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int mv[3] = {j - 1, j, j + 1};
            if (mv[0] < 1)
                mv[0] = j;
            if (mv[2] > n)
                mv[2] = j;
            f[i][j] = max(f[i - 1][mv[0]], max(f[i - 1][mv[1]], f[i - 1][mv[2]])) + a[i][j];
        }
    }
    cout << max(f[px][py], max(f[px][py - 1], f[px][py + 1]));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}
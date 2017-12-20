#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 11;
int map[maxn][maxn];
int f[maxn][maxn][maxn][maxn];
int n;
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline int max(int a, int b, int c, int d) 
{
    return max(a, max(b, max(c, d)));
}
int main()
{
    memset(map, 0, sizeof(map));
    ios::sync_with_stdio(false);
    cin >> n;
    while(1)
    {
        int x, y, v;
        cin >> x >> y >> v;
        if (x == 0 && y == 0 && v == 0)
            break;
        map[x][y] = v;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= n; l++)
                {
                    f[i][j][k][l] = max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1], f[i][j - 1][k][l - 1], f[i][j - 1][k - 1][l]) + map[i][j] + map[k][l];
                    if (i == k && j == l)
                        f[i][j][k][l] -= map[i][j];
                }
    cout << f[n][n][n][n];
    return 0;
}
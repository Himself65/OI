#include<iostream>

#define ll long long
ll a, b, n, m, l[22][22], map[23][23];
using namespace std;
void init(ll x, ll y)
{
    map[x][y]=1;
    map[x-1][y-2]=1;
    map[x-2][y-1]=1;
    map[x-2][y+1]=1;
    map[x-1][y+2]=1;
    map[x+1][y-2]=1;
    map[x+2][y-1]=1;
    map[x+2][y+1]=1;
    map[x+1][y+2]=1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> a >> b;
    init(a, b);
    l[1][0] = 1;
    for (int i = 1; i <= n + 1; ++i)
    {
        for (int j = 1; j <= m + 1; ++j)
        {
            l[i][j] = l[i - 1][j] + l[i][j - 1];
            if (map[i - 1][j - 1])
                l[i][j] = 0;
        }
    }
    cout << l[n + 1][m + 1];
    return 0;
}
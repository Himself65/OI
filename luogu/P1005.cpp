#include<iostream>
#include<cmath>
#define INIT                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define ll long long
using namespace std;
const int maxn = 85;
ll map[maxn][maxn];
int m, n;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

inline int max(int a, int b, int c, int d)
{
    return max(a, max(b, max(c, d)));
}

inline void init() 
{

}

int main()
{
    INIT;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> map[i][j];
        }
    }

    ll ans = -0x7f7f7f7f;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            for (int k = 1; k <= m; k++)    // m次
            {
                max
            }
        }
    }

    return 0;
}
#include <cstring>
#include <iostream>
using namespace std;
const int maxv = 20000 + 10;
const int maxn = 30 + 5;
int dp[maxv];
int v;
int w[maxn];
int n;
inline int min(int a, int b)
{
    return a < b ? a : b;
}
inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline void solve()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = v; j >= w[i]; j--)
        {
            if (dp[j] < dp[j - w[i]] + w[i])
            {
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    solve();
    cout << v - dp[v];
    return 0;
}
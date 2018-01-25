#include <iostream>
using namespace std;
int t, m;
struct Node
{
    int t, v;
} a[105];
int dp[1005][1005];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].t >> a[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            if (j >= a[i].t)
            {
                dp[i][j] = max(dp[i - 1][j - a[i].t] + a[i].v, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][t];
    return 0;
}
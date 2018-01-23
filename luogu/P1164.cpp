#include <iostream>
using namespace std;
const int maxn = 100 + 5;
const int maxm = 10000 + 5;
int m, n;
int a[maxn];
int dp[maxm];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= a[i]; j--)
        {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m];
    return 0;
}
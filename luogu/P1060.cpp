#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 30;
int n, m;
ll v[maxn];
ll cost[maxn];
ll dp[30005];
inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}

inline void solve()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = n - cost[i]; j >= 0; j--)
        {
            dp[j + cost[i]] = max(dp[j] + v[i], dp[j + cost[i]]);
        }
    }
    cout << dp[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cost[i] = t1;
        v[i] = t1 * t2;
    }
    solve();
    return 0;
}
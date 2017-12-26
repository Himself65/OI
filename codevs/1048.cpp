#include<iostream>
#include<cmath>
#define INIT                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0)
using namespace std;
const int maxn = 100 + 5; 
const int INF = 0x3f3f3f3f;
int a[maxn];
int dp[maxn][maxn];
int sum[maxn];
int n;

inline int min(int a,int b)
{
    return a < b ? a : b;
}

inline void init()
{
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
}
int main()
{
    INIT;
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            int pos = j + i - 1;
            for (int k = i; k < pos; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}
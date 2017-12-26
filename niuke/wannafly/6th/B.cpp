#include<iostream>
using namespace std;
const int maxn = 13;
double a[maxn], b[maxn], c[maxn];
double p[maxn];
double dp[maxn][maxn];
int main()
{
    for (int i = 1; i <= 12; i++)
    {
        scanf("%lf", &a[i]);
    }
    for (int i = 1; i <= 12; i++)
    {
        scanf("%lf", &b[i]);
    }
    for (int i = 1; i <= 12; i++)
    {
        scanf("%lf", &c[i]);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= 12; i++)
    {
        p[i] = 1 - (1 - a[i]) * (1 - b[i]) * (1 - c[i]); //计算每个的成功的几率
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = (1 - p[i]) * dp[i - 1][j] + p[i] * dp[i - 1][j - 1]; //各个数的题成功几率
        }
    }
    for (int i = 0; i <= 12; i++)
    {
        printf("%.6lf\n", dp[12][i]);
    }
    return 0;
}
#include <iostream>
#define ll long long
using namespace std;
inline int read()
{
    int x=0;
    char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x;
}
double a[13], b[13], c[13];
double dp[13][13], p[13];
int main()
{
    int i,j;
    for (i=1;i<=12;i++)
    {scanf ("%lf",&a[i]);}
    for (i=1;i<=12;i++)
    {scanf ("%lf",&b[i]);}
    for (i=1;i<=12;i++)
    {scanf ("%lf",&c[i]);}
    dp[0][0] = 1;
    for (i = 1; i <= 12; i++)
    {
        p[i] = 1 - (1 - a[i]) * (1 - b[i]) * (1 - c[i]);
        for (j = 0; j <= i; j++)
        {
            dp[i][j] = (1 - p[i]) * dp[i - 1][j] + p[i] * dp[i - 1][j - 1];
        }
    }
    for (i=0;i<=12;i++)
    {
        printf("%.6lf\n", dp[12][i]);
    }
    return 0;
}
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 10000;
const int maxd = 30;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
int maxdp[maxn][maxd];
int mindp[maxn][maxd];
int a[maxn];
int n, m;
int lg2 = log(2.0);

inline void build()
{
    for (int i = 1; i <= n; i++)
    {
       maxdp[i][0] = a[i];
       mindp[i][0] = a[i];
    }
    int k = floor(log((double)n) / lg2);
    for (int j = 1; j <= k; j++)
        for (int i = n; i >= 1; i--)
        {
            if (i + (1 << (j - 1)) <= n)
            {
                maxdp[i][j] = max(maxdp[i][j - 1], maxdp[i + (1 << (j - 1))][j - 1]);
                mindp[i][j] = min(mindp[i][j - 1], mindp[i + (1 << (j - 1))][j - 1]);
            }
        }
}

int main()
{
    return 0;
}
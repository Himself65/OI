#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

const int MAXN = 40;

using namespace std;

int n, a, b, x[MAXN], y[MAXN];

long long work()
{
    map<int, int> M;
    int p = n / 2, q = n - p;
    long long ans = 0;
    for (int i = 0; i < (1 << p); i++)
    {
        // 枚举子集
        int curA = 0, curB = 0;
        for (int j = 1; j <= p; j++)
        {
            if (i >> (j - 1) & 1)
            {
                curA += x[j], curB += y[j];
            }
        }
        M[a * curB - b * curA]++;
    }
    for (int i = 0; i < (1 << q); i++)
    {
        int curA = 0, curB = 0;
        for (int j = p + 1; j <= n; j++)
        {
            if (i >> (j - p - 1) & 1)
            {
                curA += x[j], curB += y[j];
            }
        }
        int need = a * curB - b * curA;
        ans += M[-need];
    }
    return ans - 1;
}

int main()
{
    scanf("%d %d %d", &n, &a, &b); // a / b
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &x[i], &y[i]); // x[i] / y[i]
    }
    long long ans = LLONG_MAX;
    ans = min(ans, work());
    printf("%lld\n", ans);
    return 0;
}
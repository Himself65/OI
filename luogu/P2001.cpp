#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn = 2e6 + 5;
ll n, m;
ll a[maxn];
long long read()
{
    char c;
    c = getchar();
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    long long ans = 0;
    do
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    } while (c <= '9' && c >= '0');
    return ans;
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    if (a[1] != 1)
    {
        printf("No answer!!!");
    }
    else
    {
        ll p = 1, x = 1;
        for (ll i = 1; i; i++)
            if (a[i] > x + 1 || i > n)
            {
                i--;
                if (x >= m)
                {
                    printf("%lld", p);
                    return 0;
                }
                if (i == n)
                {
                    p += (m - x) / a[i];
                    if ((m - x) % a[i])
                        p++;
                    printf("%lld", p);
                    return 0;
                }
                while (a[i + 1] > x + 1 && x < m)
                {
                    x += a[i];
                    p++;
                }
            }
    }
    return 0;
}
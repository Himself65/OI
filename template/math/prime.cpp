#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x + 0.5); i++)
        if (x % i == 0)
            return false;
    return true;
}
const int maxn = 1e5 + 5;
int f[maxn];
bool vis[maxn];
void sieve(int n)
{
    int m = sqrt(n + 0.5);
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= m; i++)
        if (vis[i]) // 如果它是素数
            for (int j = i * i; j <= n; j += i)
                vis[j] = false;
}
void sieve_log(int n)
{
    memset(vis, true, sizeof(vis));
    for (int i = 2; i * i <= n; i++)
        if (vis[i])
            for (int j = i + i; j <= n; j += i)
                vis[i] = false;
}
int ans[maxn];
void get_primes(int n)
{
    sieve(n);
    int c = 0;
    for (int i = 2; i <= n; i++)
        if (!vis[i])
            ans[++c] = i;
}
int main()
{
    int x;
    x = 101;
    cout << isPrime(x) << endl;
    x = 1001;
    cout << isPrime(x) << endl;
    get_primes(10000);
    cout << vis[101] << endl;
    cout << vis[1001] << endl;
    system("pause");
    return 0;
}
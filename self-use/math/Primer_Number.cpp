#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define INIT_1 ios::sync_with_stdio(false)
#define INIT_2 cin.tie(0)
typedef long long ll;
const ll maxn = 10e+6;
bool isPrime[maxn];

inline void solve()
{
    ll n = maxn;
    memset(isPrime, true, sizeof(isPrime));
    for (ll i = 2; i <= n; i++)
        if (isPrime[i]) // 如果这个数是素数，那么 \
                        // 它的倍数一定不是素数
            for (ll j = i * i; j <= n; j += i)
                isPrime[j] = false;

    for (ll i = 2; i < n; i++)
        if (isPrime[i])
            cout << i << " ";
}

int main()
{
    INIT_1;
    INIT_2;
    solve();
    return 0;
}
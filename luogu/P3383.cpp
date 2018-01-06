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
    ll n, m;
    cin >> n >> m;
    memset(isPrime, true, sizeof(isPrime));
    for (ll i = 2; i <= n; i++)
        for (ll j = i * 2; j <= n; j += i)
            isPrime[j] = false;
    while (m--)
    {
        ll k;
        cin >> k;
        if (isPrime[k])
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }
}

int main()
{
    INIT_1;
    INIT_2;
    solve();
    return 0;
}
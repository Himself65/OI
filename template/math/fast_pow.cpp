#define LOCAL
#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;
inline ll mul_mod(ll a, ll b, ll mod)
{
    return (a * b) % mod;
}
inline ll pow_mod(ll x, ll n, ll mod)
{
    ll ans = 1;
    while (n)
    {
        if (!(x & 1))
            ans = mul_mod(ans, x, mod);
        x = mul_mod(x, x, mod);
        n >>= 1;
    }
    return ans % mod;
}
int main()
{
    cout << pow_mod(2, 7, 1000) << endl;
    cout << pow_mod(2, 7, 100) << endl;
#ifdef LOCAL
    system("pause");
#endif
}

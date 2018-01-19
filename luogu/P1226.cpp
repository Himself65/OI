#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll b, p, k;

ll mod_pow(ll x, ll n, ll mod)
{
    ll ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    INIT_CIN; // std::cin的优化
    cin >> b >> p >> k;
    printf("%lld^%lld mod %lld=%lld", b, p, k, mod_pow(b, p, k));
    return 0;
}

// “b^p mod k=s”
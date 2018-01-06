#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
const int maxn = 10000 + 5;
bool tree[maxn];
int main()
{
    INIT_CIN;   // std::cin的优化
    memset(tree, true, sizeof(tree));
    ll l, m;
    cin >> l >> m;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        for (ll i = a; i <= b; i++)
            tree[i] = false;
    }
    ll ans = 0;
    for (int i = 0; i <= l; i++)
        if (tree[i])
            ans++;
    cout << ans;
    return 0;
}
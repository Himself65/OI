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
const int maxn = 1e+6 + 5;
ll n, a[maxn], id[maxn], q;
inline bool cmp(ll x, ll y)
{
    return a[x] > a[y];
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1, id + 1 + n, cmp);
    cin >> q;
    for (ll i = 1; i <= q; i++)
    {
        ll t;
        cin >> t;
        cout << id[t] << endl;
    }
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
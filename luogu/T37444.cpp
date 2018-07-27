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
ll n, m, sum1, sum2, t;
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t, sum1 += ((i * i) + (j * j)) * t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t, sum2 += ((i * i) + (j * j)) * t;
    cout << (ll)(sum1 - sum2) / 2 << endl;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
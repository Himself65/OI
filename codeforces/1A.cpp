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
ll a, m, n;
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m >> a;
    ll x = 0, y = 0;
    x = n % a == 0 ? n / a : n / a + 1;
    y = m % a == 0 ? m / a : m / a + 1;
    cout << x * y;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
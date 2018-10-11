// #define LOCAL // For Windows
// #define TEST
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
const int maxn = 2e5 + 5;
int n, k;
ll maxh = -1, ans, s;
ll a[maxn];
ll h[maxn];
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        h[a[i]]++;
        maxh = max(a[i], maxh);
    }
    for (int i = maxh; i >= 1; i--)
    {
        h[i - 1] += h[i];
    }
    for (int i = maxh; i >= 1; i--)
    {
        s += h[i];
        if (s > k)
        {
            ans++;
            s = 0;
            i++; // 不算这回
        }
        if (h[i] == n)
        {
            if (s - h[i] > 0)
                ans++;
            break;
        }
    }
    cout << ans;
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
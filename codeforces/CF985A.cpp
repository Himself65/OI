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
const int maxn = 100 + 5;
int n, m, a[maxn], ans1, ans2, b[maxn], c[maxn];
inline int abs(int x) { return x > 0 ? x : -x; }
inline int min(int a, int b) { return a < b ? a : b; }
inline bool cmp(const int &a, const int &b) { return a < b; }
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
        cin >> a[i];
    sort(a + 1, a + n / 2 + 1, cmp);
    for (int i = 1; i <= n / 2; i++)
    {
        b[i] = i * 2 - 1;
        c[i] = i * 2;
        ans1 += abs(b[i] - a[i]);
        ans2 += abs(c[i] - a[i]);
    }
    int ans = min(ans1, ans2);
    cout << ans;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
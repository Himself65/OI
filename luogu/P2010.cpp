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
int s[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, n, m, c, sum;
inline void solve()
{
    int ans = 0;
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= s[i]; j++)
        {
            c = (j % 10) * 1000;
            c += (j / 10) * 100;
            c += (i % 10) * 10;
            c += (i / 10);
            sum = c * 10000 + i * 100 + j;
            if (sum < n || sum > m)
                continue;
            ans++;
        }
    cout << ans << endl;
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m;
    solve();
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
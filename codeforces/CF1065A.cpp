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
int T;
int s, a, b, c;
int main()
{
    INIT_CIN; // std::cin的优化
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &s, &a, &b, &c);
        ll ans = (s / c) + ((ll)((s / c) / (a)) * (b));
        cout << ans << endl;
    }
#ifdef TEST
#endif
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
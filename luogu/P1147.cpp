#define LOCAL // For Windows
#define TEST
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
int m;
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> m;
    int range = sqrt(2 * m);
    // ( L + R ) * ( R - L + 1 ) = 2M
    for (int k1 = range; k1 > 1; k1--)
        if ((2 * m) % k1 == 0 && (k1 + 2 * m / k1) % 2)
        {
            int k2 = 2 * m / k1;
            printf("%d %d\n", (k2 - k1 + 1) / 2, (k1 + k2 - 1) / 2);
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
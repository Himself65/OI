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
const int maxn = 200 + 5;
// data
int n, m, t;
struct Node
{
    int money, time;
} a[maxn];
int f[maxn][maxn];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i].money >> a[i].time;

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i].money; j--)
            for (int k = t; k >= a[i].time; k--)
                f[j][k] = max(f[j][k], f[j - a[i].money][k - a[i].time] + 1);
    cout << f[m][t];
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
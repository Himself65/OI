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
const int maxn = 1e+3 + 5;
int n, a[maxn];
struct node
{
    int num, cnt;
} b[maxn];
inline bool cmp(const node &a, const node &b) { return a.cnt > b.cnt; }
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        b[i].num = i;
        cin >> t;
        b[t].num++;
    }
    sort(b + 1, b + 1 + n, cmp);
    cout << b[1].num;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
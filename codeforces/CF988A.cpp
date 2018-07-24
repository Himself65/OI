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
int n, k, a[maxn], tag[maxn], len;
bool b[maxn];
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!b[a[i]])
            tag[++len] = i;
        b[a[i]] = true;
    }
    if (k <= len)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= k; i++)
        cout << tag[i] << " ";
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
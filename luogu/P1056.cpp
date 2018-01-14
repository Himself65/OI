#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #define LOCAl
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll m, n, k, l, d;
struct People
{
    int p, n;
    People() : n(0) {}
} v[2005], h[2005]; // 竖直 水平
inline bool cop1(People a, People b)
{
    return a.n > b.n;
}
inline bool cop2(People a, People b)
{
    return a.p < b.p;
}
int main()
{
    INIT_CIN;
    cin >> m >> n >> k >> l >> d;
    for (int i = 1; i <= d; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            v[min(y1, y2)].p = min(y1, y2);
            v[min(y1, y2)].n++;
        }
        else if (y1 == y2)
        {
            h[min(x1, x2)].p = min(x1, x2);
            h[min(x1, x2)].n++;
        }
    }
    sort(v + 1, v + 1000 + 1, cop1);
    sort(h + 1, h + 1000 + 1, cop1);
    sort(v + 1, v + 1 + l, cop2);
    sort(h + 1, h + 1 + k, cop2);
    for (int i = 1; i <= k; i++)
        cout << h[i].p << " ";
    cout << endl;
    for (int i = 1; i <= l; i++)
        cout << v[i].p << " ";
    return 0;
}
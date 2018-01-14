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
ll n;
ll heap[10005];
ll ans = 0;
priority_queue<ll, vector<ll>, greater<ll> > q;
inline bool compare(ll a, ll b)
{
    return a < b ? a : b;
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll t;
        cin >> t;
        q.push(t);
    }
    while (q.size() > 1)
    {
        ll a = q.top();
        q.pop();
        ll b = q.top();
        q.pop();
        q.push(a + b);
        ans += a + b;
    }
    cout << ans;
    return 0;
}
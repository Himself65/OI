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
ll a[100005];
ll n, m;
int main()
{
    INIT_CIN;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n;)
    {
        ll temp = 0;
        while (temp + a[i] <= m)
        {
            temp += a[i];
            i++;
        }
        ans++;
    }
    cout << ans;
    return 0;
}
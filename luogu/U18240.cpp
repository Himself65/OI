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

int main()
{
    INIT_CIN; // std::cin的优化
    int n;
    ll ans = 0;
    cin >> n;
    while (n--)
    {
        ll t;
        cin >> t;
        ans += t;
    }
    cout << ans;
    return 0;
}
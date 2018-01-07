#include <algorithm>
#include <cmath>
#include <cstdio>
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
typedef double db;
typedef pair<ll, ll> pii;
const int maxn = 1000 + 5;
const int INF = 0x7f7f7f7f;
const int SUP = -0x7f7f7f7f;
ll dp[1000 + 5];
int main()
{
    ll num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            dp[i] += dp[j];
        }
        dp[i]++;
    }
    cout << dp[num];
    return 0;
}
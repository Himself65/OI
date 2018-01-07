#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100 + 5;
ll a[maxn];
bool vis[maxn];
int main()
{
    INIT_CIN;   // std::cin的优化
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (a[i] + a[j] == a[k] && vis[k] == 0)
                {
                   ans++;
                   vis[k] = 1;
                }
    cout << ans;
    return 0;
}
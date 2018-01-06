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
ll q[maxn];
ll ans[maxn];
int main()
{
    INIT_CIN;   // std::cin的优化
    int n;
    memset(ans, 0, sizeof(ans));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        for (int j = 1; j < i; j++)
        {
            if (q[j] < q[i])
                ans[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
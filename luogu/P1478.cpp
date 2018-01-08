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
const int maxn = 5000 + 5;
int n, s, a, b;
struct Apple
{
    int a;
    int f;
} apple[maxn];
bool compare(Apple &a, Apple &b)
{
    return a.f < b.f;
}
int main()
{
    INIT_CIN;   // std::cin的优化
    cin >> n >> s >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> apple[i].a >> apple[i].f;
    }
    sort(&apple[0], &apple[n], compare);
    int i = 0;
    ll ans = 0;
    while (s > 0)
    {
        if (a + b >= apple[i].a)
        {
            s -= apple[i].f;
            if (s < 0)
                break;
            ans++;
        }
        i++;
    }
    cout << ans;
    return 0;
}
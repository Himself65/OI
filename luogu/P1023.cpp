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
ll prize, ans = -0x7f7f7f7f, one;
ll def, sell;
inline ll max(ll a, ll b)
{
    return a > b ? a : b;
}
string noans = "NO SOLUTION";
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> prize;
    int a, b;
    int d;
    int ans = 0;
    while (true)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        int p = (prize - a) * b;
        ans = max(p, ans);
    }
    cin >> d;
    return 0;
}
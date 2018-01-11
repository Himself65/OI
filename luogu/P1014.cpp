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
ll n, l, r;
bool iseven;
inline void solve()
{
    ll sum = 0;
    ll i = 0;
    while (++i)
    {
        if (n >= sum+1 && n <= sum + i)
        {
            iseven = (i % 2 == 0);
            l = 1;
            r = i;
            while(true)
            {
                sum++;
                if (sum >= n)
                    return;
                l++;
                r--;
            }
        }
        sum += i;
    }
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    solve();
    if (iseven)
        cout << l << "/" << r;
    else
        cout << r << "/" << l;
    return 0;
}
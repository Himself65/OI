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

inline uint max(uint a, uint b)
{
    return a > b ? a : b;
}
int main()
{
    INIT_CIN;   // std::cin的优化
    ll n;
    cin >> n;
    ll t1;
    cin >> t1;
    ll maxt = 1, maxsofar = 1;
    for (int i = 2; i <= n; i++)
    {
        ll ti;
        cin >> ti;
        if (t1 < ti)
            maxsofar++;
        else
            maxsofar = 1;
        maxt = max(maxt, maxsofar);
        t1 = ti;
    }
    cout << maxt;
    return 0;
}
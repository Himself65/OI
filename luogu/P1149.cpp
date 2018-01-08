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
const int maxn = 1000 + 5;
const int INF = 0x7f7f7f7f;
const int SUP = -0x7f7f7f7f;
const int number[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll ans = 0;
inline int check(int x)
{
    int num = 0;
    while (x / 10 != 0)
    {
        num += number[x % 10];
        x = x / 10;
    }
    num += number[x];
    return num;
}

inline void solve(int n)
{
    for (int i = 0; i <= 1111; i++)
    {
        for (int j = 0; j <= 1111; j++)
        {
            int k = i + j;
            if (check(i) + check(j) + check(k) == n)
                ans++;
        }
    }
}

int main()
{
    INIT_CIN;   // std::cin的优化
    int n;
    cin >> n;
    n -= 4;
    solve(n);
    cout << ans;
    return 0;
}
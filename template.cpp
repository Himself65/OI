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
inline ll max(int a, int b)
{
    return a > b ? a : b;
}
inline ll min(int a, int b)
{
    return a < b ? a : b;
}
inline ll up(int x, int a)  //返回两数相除的上取整
{
    return (x / a) * a < x ? (x / a) + 1 : x / a;
}
int main()
{
    INIT_CIN;   // std::cin的优化
    cout << maxn << endl
         << INF << endl
         << SUP;
    return 0;
}
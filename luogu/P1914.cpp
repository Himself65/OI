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

int main()
{
    INIT_CIN;   // std::cin的优化
    int n;
    cin >> n;
    string c;
    cin >> c;
    for (int i = 0; i < c.length(); i++)
    {
        putchar((c[i] - 'a' + n) % 26 + 'a');
    }
    return 0;
}
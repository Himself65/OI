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
const int maxn = 100 + 5;
int n, s, ans;
inline bool isReverse(int num, int k)
{
    int i = 0, j = 0, point = 0, ch[maxn] = {0};
    while (num)
        ch[point++] = num % k, num /= k;
    j = point - 1;
    while (i < j)
        if (ch[i++] != ch[j--])
            return false;
    return true;
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> s;
    for (int i = s + 1; ans < n; i++)
    {
        int cnt = 0;
        for (int j = 2; j <= 10 && cnt < 2; j++)
            if (isReverse(i, j))
                cnt++;
        if (cnt >= 2)
            cout << i << endl, ans++;
    }
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
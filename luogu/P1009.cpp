#define LOCAL // For Windows
#define TEST
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
const int maxn = 1e3 + 5;
int t[maxn], s[maxn], n, l = 1, len = 1;
inline void mul(int x)
{
    for (int i = 1; i <= l; i++)
        t[i] *= x;
    for (int i = 1; i <= l; i++)
    {
        t[i + 1] += (t[i] / 10);
        t[i] %= 10;
        if (i == l && t[i + 1] != 0)
            l++; // 进位
    }
}
inline void add()
{
    int max_len = max(len, l);
    for (int i = 1; i <= max_len; i++)
        s[i] += t[i];
    for (int i = 1; i <= max_len; i++)
    {
        s[i + 1] += (s[i] / 10);
        s[i] %= 10;
        if (i == max_len)
        {
            if (s[i + 1])
                len = i + 1;
            else
                len = i;
        }
    }
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    t[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        mul(i);
        add();
    }
    for (int i = len; i >= 1; i--)
        cout << s[i];
    cout << endl;
#ifdef TEST
#endif
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
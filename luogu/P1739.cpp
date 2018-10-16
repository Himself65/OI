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
stack<char> s;
int main()
{
    INIT_CIN; // std::cin的优化
    char c;
    bool ok = true;
    while (scanf("%c", &c) != -1)
    {
        if (c == ')' && s.empty())
        {
            ok = false;
            break;
        }
        else if (c == ')' && !s.empty() && s.top() == '(')
            s.pop();
        else if (c == '(')
            s.push(c);
    }
    if (!s.empty())
        ok = false;
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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
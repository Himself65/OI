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
const int maxn = 10000 + 5;
int l, n, op, lc, rc, mv, pt;
int tree[maxn];
int main()
{
    INIT_CIN; // std::cin的优化
    scanf("%d%d", &l, &n);
    memset(tree, 1, sizeof(tree));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &op, &lc, &rc);
        if (op == 0)
        {
            for (int j = lc; j <= rc; j++)
            {
                if (tree[j] == 2)
                    mv++; // 砍掉
                tree[j] = 0;
            }
        }
        else
        {

            for (int j = lc; j <= rc; j++)
            {
                if (tree[j] == 0)
                    tree[j] = 2;
            }
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (tree[i] == 2)
            pt++;
    }
    cout << pt << endl
         << mv;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
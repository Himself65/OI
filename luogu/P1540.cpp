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
#include <cmath>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
bool haveSave[1005];
queue<int> q;
int n, m;
int ans = 0;
inline void save(int x)
{
    if (haveSave[x])
        return;
    if (q.size() == m)
    {
        haveSave[q.front()] = false;
        q.pop();
    }
    haveSave[x] = true;
    q.push(x);
    ans++;
}
int main()
{
    INIT_CIN; // std::cin的优化
    memset(haveSave, false, sizeof(haveSave));
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        save(temp);
    }
    cout << ans;
    return 0;
}
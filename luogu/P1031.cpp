#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #define LOCAl
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int n, ave, ans;
int heap[105];
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> heap[i];
        ave += heap[i];
    }
    ave /= n;
    for (int i = 1; i <= n; i++)
        heap[i] -= ave;
    for (int i = 1; i <= n; i++)
        if (heap[i] == 0)
            continue;
        else
        {
            heap[i + 1] += heap[i];
            ans++;
        }
    cout << ans;
    return 0;
}
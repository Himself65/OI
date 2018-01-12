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
int n;
string maxs;
inline bool check(string a, string b)
{
    if (a.length() > b.length())
        return true;
    else if (a.length() == b.length())
        for (int i = 0; i < a.length(); i++)
        {            
            if (a[i] > b[i])
                return true;
            else if (a[i] == b[i])
                continue;
            else
                return false;
        }
    return false;
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    int maxn = 1;
    string maxnow;
    cin >> maxnow;
    for (int i = 2; i <= n; i++)
    {
        cin >> maxs;
        if (check(maxs, maxnow)) // 现在的和读取的交换，如果true交换
        {
            maxn = i;
            maxnow = maxs;
        }
    }
    cout << maxn << endl
         << maxnow;
    return 0;
}
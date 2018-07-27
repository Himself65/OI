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
string n;
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    while (true)
    {
        if (n.length() == 1)
            break;
        else
        {
            ll temp = 1;
            for (int i = 0; i < n.length(); i++)
            {
                if (n[i] != '0')
                    temp *= n[i] - '0';
            }
            cout << temp << endl;
            n = to_string(temp);
        }
    }
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
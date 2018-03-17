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
string a[5][3];
string he[100];
string me[100];
int main()
{
    INIT_CIN; // std::cin的优化
    for (int i = 1; i <= 3; i++)
    {
        cin >> a[i][1] >> a[i][2];
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> he[i];

        bool fake = true;
        for (int j = 1; j <= 3; j++)
        {
            if (he[i] == a[j][1])
            {
                fake = false;
                break;
            }
        }
        if (fake)
        {
            me[i] = "Fake";
        }
        else
            for (int j = 1; j <= 3; j++)
            {
                if (he[i] == a[j][2])
                {
                    me[i] = a[j][1];
                    break;
                }
            }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << me[i] << endl;
    }
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
/*

stone sci
sci paper
paper stone
4
stone
sci
spock
paper

*/
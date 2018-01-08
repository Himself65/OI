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
int n;
int num = 0;
ll ans = 0;
const string s[4] = {"1", "1", "2", "3"};
queue<string> vs;
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int x1 = 1; x1 <= 3; x1++)
        for (int x2 = 1; x2 <= 3; x2++)
            for (int x3 = 1; x3 <= 3; x3++)
                for (int x4 = 1; x4 <= 3; x4++)
                    for (int x5 = 1; x5 <= 3; x5++)
                        for (int x6 = 1; x6 <= 3; x6++)
                            for (int x7 = 1; x7 <= 3; x7++)
                                for (int x8 = 1; x8 <= 3; x8++)
                                    for (int x9 = 1; x9 <= 3; x9++)
                                        for (int x10 = 1; x10 <= 3; x10++)
                                            if (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 == n)
                                            {
                                                ans++;
                                                string str = "";
                                                str = s[x1] + " " + s[x2] + " " + s[x3] + " " + s[x4] + " " + s[x5] + " " + s[x6] + " " + s[x7] + " " + s[x8] + " " + s[x9] + " " + s[x10];
                                                vs.push(str);
                                            }
    if (ans == 0)
    {
        cout << "0";
        return 0;
    }
    cout << ans << endl;
    while (!vs.empty())
    {
        cout << vs.front() << endl;
        vs.pop();
    }
    return 0;
}
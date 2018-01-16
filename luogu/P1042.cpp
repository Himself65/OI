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
string key[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35"};

inline void solve()
{
    char ch;
    pair<int, int> a, b;
    queue<string> qa, qb;
    while (true)
    {
        cin >> ch;
        if (ch == 'E' || ch == EOF)
            break;
        if (ch == 'W')
        {
            a.first++;
            b.first++;
        }
        else
        {
            a.second++;
            b.second++;
        }
        if ((a.first >= 21 || a.second >= 21) && abs(a.first - a.second) >= 2)
        {
            qa.push(to_string(a.first) + ":" + to_string(a.second));
            a.first = a.second = 0;
        }
        if ((b.first >= 11 || b.second >= 11) && abs(b.first - b.second) >= 2)
        {
            qb.push(to_string(b.first) + ":" + to_string(b.second));
            b.first = b.second = 0;
        }
    }
    qa.push(to_string(a.first) + ":" + to_string(a.second));
    qb.push(to_string(b.first) + ":" + to_string(b.second));
    while (!qb.empty())
    {
        cout << qb.front() << endl;
        qb.pop();
    }
    cout << endl;
    while (!qa.empty())
    {
        cout << qa.front() << endl;
        qa.pop();
    }
}

int main()
{
    INIT_CIN; // std::cin的优化
    solve();
    return 0;
}
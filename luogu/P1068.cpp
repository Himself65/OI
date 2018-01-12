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
struct student
{
    int k, p;
};
inline bool compare(student &a, student &b)
{
    if (a.p == b.p)
        return a.k < b.k;
    return a.p > b.p;
}
student stu[5010];
int n, m;
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> stu[i].k >> stu[i].p;
    sort(stu, stu + n, compare);
    m = floor((double)m * 1.5);
    int point = stu[m - 1].p;
    int num = 0;
    queue<student> q;
    for (int i = 0;; i++)
    {
        if (stu[i].p < point)
            break;
        q.push(stu[i]);
        num++;
    }
    cout << point << " " << num << endl;
    while (!q.empty())
    {
        student &x = q.front();
        cout << x.k << " " << x.p << endl;
        q.pop();
    }
    return 0;
}
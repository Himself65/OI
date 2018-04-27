#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 1e+6 + 5;
int n, m;
struct Node
{
    string act;
    int n;
} a[maxn];
struct Move
{
    int a, s;
} mv[maxn];
int pt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].n;
        cin >> a[i].act;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> mv[i].a;
        cin >> mv[i].s;
    }
    for (int i = 0; i <= m; i++)
    {
        int xa = mv[i].a;
        int xv = mv[i].s;
        if (xv == 0)
            continue;
        if (a[pt].n ^ xa) // 1
        {
            pt = (pt + xv) % n;
        }
        else // 0
        {
            pt = (pt - (xv % n) + n) % n;
        }
    }
    cout << a[pt].act;
    return 0;
}
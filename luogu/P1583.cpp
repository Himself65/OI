#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a[20005], f[20005], e[20005];
bool cmp(int x, int y)
{
    return a[x] == a[y] ? x < y : a[x] > a[y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j, k, n;
    cin >> n >> k;
    for (i = 1; i <= 10; i++)
        cin >> e[i];
    for (i = 1; i <= n; i++)
        cin >> a[i], f[i] = i;
    sort(f + 1, f + n + 1, cmp);
    for (i = 1; i <= n; i++)
        a[f[i]] += e[(i - 1) % 10 + 1];
    sort(f + 1, f + n + 1, cmp);
    for (i = 1; i <= k; i++)
        cout << f[i] << " ";
}
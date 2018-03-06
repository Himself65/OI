#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 305;
int sum[maxn], id[maxn], Chinese[maxn];
inline void change(int i, int j)
{
    swap(sum[i], sum[j]);
    swap(id[i], id[j]);
    swap(Chinese[i], Chinese[j]);
}
inline bool ok(int i, int j)
{
    if (sum[i] < sum[j])
        return false;
    if (sum[i] == sum[j] && Chinese[i] < Chinese[j])
        return false;
    if (sum[i] == sum[j] && Chinese[i] < Chinese[j] && id[i] > id[j])
        return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, Math, English;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> Chinese[i] >> Math >> English;
        sum[i] = Chinese[i] + Math + English;
        id[i] = i;
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (!ok(i, j))
                change(i, j);
    for (int i = 1; i <= 5; ++i)
        cout << id[i] << " " << sum[i] << endl;
    return 0;
}
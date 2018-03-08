#include <algorithm>
#include <iostream>
using namespace std;
int n, m, p, i, j;
int a, b, rk[5001], set[5001];
inline void init()
{
    for (int i = 1; i <= 5001; i++)
        set[i] = i;
}
inline int find_set(int i)
{
    if (set[i] == i)
        return i;
    else
        return set[i] = find_set(set[i]);
}
inline void Union(int i, int j)
{
    i = find_set(i);
    j = find_set(j);
    if (i == j)
        return;
    if (rk[i] > rk[j])
    {
        set[j] = i;
    }
    else
    {
        set[i] = j;
        if (rk[i] == rk[j])
            rk[i]++;
    }
}
inline bool same(int a, int b) { return find_set(a) == find_set(b); }
int main()
{
    init();
    cin >> n >> m >> p;
    for (i = 1; i <= m; i++)
    {
        set[i] = i;
    }
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        Union(a, b);
    }
    for (j = 1; j <= p; j++)
    {
        cin >> a >> b;
        if (same(a, b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
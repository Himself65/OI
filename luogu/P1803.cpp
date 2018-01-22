#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1000000 + 5;
struct Node
{
    int a, b;
} edge[maxn];
int n;
inline bool compare(Node &a, Node &b)
{
    return a.b < b.b;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> edge[i].a >> edge[i].b;
    }
    sort(edge, edge + n, compare);
    int ans = 1;
    int ed = edge[0].b;

    for (int i = 1; i < n; i++)
    {
        if (edge[i].a >= ed)
        {
            ans++;
            ed = edge[i].b;
        }
    }

    cout << ans;
    return 0;
}
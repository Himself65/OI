#include<iostream>
using namespace std;
const int maxn = 10005;
struct Node
{
    int a, b, g, k;
};
Node node[maxn];
int n;
int x, y;
inline void solve()
{
    bool ok = false;
    for (int i = n; i > 0; i--)
    {
        Node &t = node[i];
        if (x >= t.a && x <= t.a + t.g && y >= t.b && y <= t.b + t.k)
        {
            ok = true;
            cout << i;  // 顺序输入的，所以不用专门记录序号
            break;
        }
    }
    if (!ok)
        cout << "-1";
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Node &t = node[i];
        cin >> t.a >> t.b >> t.g >> t.k;
    }
    cin >> x >> y;
    solve();
    return 0;
}
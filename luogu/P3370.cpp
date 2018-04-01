#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
ull base = 131;
ull a[10010];
string s;
int n, ans = 1;
ull hashs(string s)
{
    int len = s.length();
    ull ans = 0;
    for (int i = 0; i < len; i++)
        ans = ans * base + (ull)s[i];
    return ans & 0x7fffffff;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        a[i] = hashs(s);
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i - 1])
            ans++;
    cout << ans;
}
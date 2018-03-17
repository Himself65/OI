#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string a[30];
inline bool cmp(string a, string b)
{
    return a + b > b + a;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    string ans = "";
    for (int i = 1; i <= n; i++)
    {
        ans += a[i];
    }
    cout << ans;
    return 0;
}
#include <iostream>
using namespace std;
struct stu
{
    int n, s;
};
const int maxn = 2e5 + 5;
stu s[maxn];
int find(int l, int r)
{
    int i, ans = -1;
    for (i = l; i <= r; i++)
        if (s[i].s > ans)
            ans = s[i].s;
    return ans;
}
int main()
{
    int m, n, i;
    char t;
    int t1, t2;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> s[i].s;
        s[i].n = i;
    }
    while (m--)
    {
        cin >> t >> t1 >> t2;
        if (t == 'Q')
            cout << find(t1, t2) << endl;
        else if (s[t1].s < t2)
            s[t1].s = t2;
    }
    // system("pause");
    return 0;
}
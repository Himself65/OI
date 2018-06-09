#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;
bool cmp(string &a, string &b)
{
    return a.size() < b.size();
}
const int maxn = 1000 + 5;
string s[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n, cmp);
    for (int i = 0; i < n - 1; i++)
        if (s[i + 1].find(s[i]) == s[i + 1].npos)
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
    return 0;
}
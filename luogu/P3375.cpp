#include <iostream>
#include <string>
using namespace std;
int kmp[1000000 << 1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int len1 = a.length();
    int len2 = b.length();
    int k;
    for (int i = 1; i < len2; i++)
    {
        while (k && b[i] != b[k])
            k = kmp[k];
        kmp[i + 1] = b[i] == b[k] ? ++k : 0;
    }
    k = 0;
    for (int i = 0; i < len1; i++)
    {
        while (k && a[i] != b[k])
            k = kmp[k];
        k += a[i] == b[k] ? 1 : 0;
        if (k == len2)
            cout << (i - len2 + 2) << endl;
    }
    for (int i = 1; i <= len2; i++)
        cout << kmp[i] << " ";
    return 0;
}
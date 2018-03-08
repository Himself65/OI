#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
inline int max(int a, int b) { return a > b ? a : b; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int x;
    int maxx = 0;
    int maxnow = 0;
    for (int i = 0; i < n; i++)
    {
        maxnow = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (x)
                maxnow++;
        }
        maxx = max(maxnow, maxx);
    }
    cout << maxx << endl;
    return 0;
}
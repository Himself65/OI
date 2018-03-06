#include <iostream>
using namespace std;
const int maxn = 32005;
int n, m;
int v, p, q;
int miv[maxn];
int mic[maxn];
int aiw[maxn][3];
int aic[maxn][3];
int f[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p >> q;
        if (!q)
        {
            miv[i] = v;
            mic[i] = v * p;
        }
        else
        {
            aiw[q][0]++;
            aiw[q][aiw[q][0]] = v;
            aic[q][aiw[q][0]] = v * p;
        }
    }

    for (int i = 1; i <= m; i++)
        for (int j = n; miv[i] != 0 && j >= miv[i]; j--)
        {
            f[j] = max(f[j], f[j - miv[i]] + mic[i]);
            for (int k = 1; k <= 2; k++)
            {
                if (j >= miv[i] + aiw[i][k])
                    f[j] = max(f[j], f[j - miv[i] - aiw[i][k]] + mic[i] + aic[i][k]);
            }
            if (j >= miv[i] + aiw[i][1] + aiw[i][2])
                f[j] = max(f[j], f[j - miv[i] - aiw[i][1] - aiw[i][2]] + mic[i] + aic[i][1] + aic[i][2]);
        }
    cout << f[n] << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10, maxk = 110, mod = 1e9 + 7;

void judge()
{
    freopen("action.in", "r", stdin);
    freopen("action.out", "w", stdout);
    return;
}

int n, k, siz[maxn], q[maxn], par[maxn], fnt, rar, ans;
int dp[maxn][maxk][2][2], pd[maxk][2][2];
vector<int> g[maxn];

inline void Add(int &x, int y)
{
    x = x + y < mod ? x + y : x + y - mod;
    return;
}

int main()
{
    judge();
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    q[rar++] = 1;
    while (fnt != rar)
    {
        int u = q[fnt++];
        siz[u] = 1;
        dp[u][0][0][0] = dp[u][1][1][0] = 1;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int &v = g[u][i];
            if (v != par[u])
            {
                par[q[rar++] = v] = u;
            }
        }
    }
    for (int ti = rar - 1; ti; --ti)
    {
        int &u = q[ti], &p = par[u], Endu = min(siz[u], k), Endp = min(siz[p], k);
        for (int ip = 0; ip <= Endp; ++ip)
        {
            for (int xp = 0; xp < 2; ++xp)
            {
                for (int yp = 0; yp < 2; ++yp)
                {
                    pd[ip][xp][yp] = dp[p][ip][xp][yp];
                    dp[p][ip][xp][yp] = 0;
                }
            }
        }
        for (int ip = 0; ip <= Endp; ++ip)
        {
            for (int xp = 0; xp < 2; ++xp)
            {
                for (int yp = 0; yp < 2; ++yp)
                {
                    static int s;
                    if (s = pd[ip][xp][yp])
                    {
                        int End = min(Endu, k - ip);
                        for (int iu = 0; iu <= End; ++iu)
                        {
                            for (int xu = 0; xu < 2; ++xu)
                            {
                                for (int yu = xp ^ 1; yu < 2; ++yu)
                                {
                                    Add(dp[p][iu + ip][xp][yp | xu], (long long)s * dp[u][iu][xu][yu] % mod);
                                }
                            }
                        }
                    }
                }
            }
        }
        siz[p] += siz[u];
    }
    for (int xu = 0; xu < 2; ++xu)
    {
        Add(ans, dp[1][k][xu][1]);
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}
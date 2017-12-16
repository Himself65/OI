#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<functional>
using namespace std;
const int maxn = 1005;
int a, b, n;
long matrix[maxn][maxn];
long maxt = -0x7f7f7f7f;
long mint = 0x7f7f7f7f;
long d = 0x7f7f7f7f;
namespace P2216 {
    inline long max(long a,long b) {
        return a > b ? a : b;
    }
    inline long min(long a,long b) {
        return a < b ? a : b;
    }
    inline void solve() {
        for (int i = 1; i <= a - n + 1; i++)
        {
            for (int j = 1; j <= b - n + 1; j++)
            {
                long maxt = -0x7f7f7f7f;
                long mint = 0x7f7f7f7f;
                for (int k = 0; k <= n; k++)
                {
                    for (int l = 0; l <= n; l++)
                    {
                        long a = matrix[k + i][l + j];
                        maxt = P2216::max(a, maxt);
                        mint = P2216::min(a, mint);
                    }
                }   // end for
                d = P2216::min(maxt - mint, d);
            }
        }   //end for
    }
}

int main() {
    memset(matrix, -1, sizeof(matrix));
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &n);
    printf("%d %d %d\n", a, b, n);
    for (int i = 1; i <= a; i++) 
    {
        for (int j = 1; j <= b; j++)
        {
            scanf("%ld", &matrix[i][j]);
        }
    }
    P2216::solve();
    printf("%ld\n", d);
    system("pause");
    return 0;
}
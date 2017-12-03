#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
在遥远的东方，有一家糖果专卖店。
这家糖果店将会在每天出售一些糖果，它每天都会生产出m个糖果，第i天的第j个糖果价格为C[i][j]元。
现在的你想要在接下来的n天去糖果店进行选购，你每天可以买多个糖果，也可以选择不买糖果，但是最多买m个。（因为最多只生产m个）买来糖果以后，你可以选择吃掉糖果或者留着之后再吃。糖果不会过期，你需要保证这n天中每天你都能吃到至少一个糖果。
这家店的老板看你经常去光顾这家店，感到非常生气。（因为他不能好好睡觉了）于是他会额外的要求你支付点钱。具体来说，你在某一天购买了 k 个糖果，那么你在这一天需要额外支付 k2 的费用。
那么问题来了，你最少需要多少钱才能达成自己的目的呢？
 */

inline int read(){
	int x=0;char ch=' ';int f=1;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
#define ll int
const int maxn = 300 + 5;
const ll INF = 0x3f3f3f3f;
int n, m;
ll c[maxn][maxn];
ll dp[maxn][maxn];
ll sum[maxn][maxn];
inline void solve() {
    memset(sum, 0, sizeof(maxn));
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i][j - 1] + c[i][j];
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] > INF)
                continue;
            for (int k = 0; k <= m; k++) {
                if (j == 0 && k == 0)
                    continue;
                dp[i + 1][j + k - 1] = min(dp[i + 1][j + k - 1], dp[i][j] + sum[i + 1][k] + k * k);
            }
        }
    }
}

int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= m;j++) {
            c[i][j] = read();
        }
        sort(c[i] + 1, c[i] + m + 1);
    }
    solve();
    printf("%d\n", dp[n][0]);
    system("pause");
    return 0;
}
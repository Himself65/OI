#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#define LOCAL
using namespace std;
const int maxn = 55;

int node[maxn][maxn];
int d[maxn][maxn][maxn][maxn];
int n, m;
inline int read(){
	int x=0;char ch=' ';int f=1;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline int max(int a, int b) {
    return a > b ? a : b;
}
inline void display() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
#ifdef LOCAL
    freopen("debug\\P1006.in", "r", stdin);
    freopen("debug\\P1006.out", "w", stdout);
#endif
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int temp = 0;
            temp = read();
            node[i][j] = temp;
        }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                for(int l=1;l<=n;l++){
                    if((i==k&&j==l)&&(i!=m)&&(j!=n))
                        continue;
                    d[i][j][k][l] = max(d[i - 1][j][k - 1][l], max(d[i - 1][j][k][l - 1], max(d[i][j - 1][k - 1][l], d[i][j - 1][k][l - 1]))) + node[i][j] + node[k][l];
                }
            }
        }
    }
    printf("%d\n", d[m][n - 1][m - 1][n]);
#ifdef LOCAL
//    display();
    fclose(stdin);
    fclose(stdout);
#endif
//    system("pause");
    return 0;
}
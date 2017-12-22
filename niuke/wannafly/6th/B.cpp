#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define N 12
ld a[N + 3], b[N + 3], c[N + 3], ex[N + 3][N + 3];
int main()
{
    for (int i = 1; i <= N; ++i)
        cin >> a[i];
    for (int i = 1; i <= N; ++i)
        cin >> b[i];
    for (int i = 1; i <= N; ++i)
        cin >> c[i];
    ex[0][0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        ld p = (1 - a[i]) * (1 - b[i]) * (1 - c[i]);
        for (int j = 0; j <= N; ++j)
            ex[i][j] += ex[i - 1][j] * p,
                ex[i][j + 1] += ex[i - 1][j] * (1 - p);
    }
    for (int i = 0; i <= N; ++i)
        printf("%.6lf\n", ex[N][i]);
    return 0;
}
#define LOCAL  // For Windows
#define DEBUG
// #define DATA
#define HAND
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN               \
  ios::sync_with_stdio(false); \
  cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int maxn = 30;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD {
template <class T>
inline void read_int(T &x) {
  char ch = getchar();
  int op = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  x = 0;
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch - '0'), ch = getchar();
  x *= op;
}
template <class T>
inline void put_int(T x) {
  static char _buf[1000];
  int p = 0;
  if (x < 0) putchar('-'), x = -x;
  do {
    _buf[p++] = '0' + (x % 10), x /= 10;
  } while (x);
  for (int i = p - 1; i >= 0; --i) putchar(_buf[i]);
}
int n, m, r, c;
int a[maxn][maxn];
int f[maxn][maxn], seat[maxn];
int w[maxn], v[maxn][maxn];
int ans = INF;
void dp() {
  memset(v, 0, sizeof(v)), memset(w, 0, sizeof(w)), memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j < r; ++j) w[i] += abs(a[seat[j]][i] - a[seat[j + 1]][i]);
  for (int i = 1; i <= m; ++i)
    for (int j = i + 1; j <= m; ++j)
      for (int k = 1; k <= r; ++k)
        v[i][j] += abs(a[seat[k]][i] - a[seat[k]][j]);
  f[0][0] = 0;
  for (int i = 1; i <= c; ++i)
    for (int j = i; j <= m; ++j)
      for (int k = 0; k < j; ++k)
        f[i][j] = min(f[i][j], f[i - 1][k] + w[j] + v[k][j]);
  for (int i = c; i <= m; ++i) ans = min(ans, f[c][i]);
}
void dfs(int x, int pre) {
  if (pre > r)
    dp();
  else if (x > n)
    ;
  else
    dfs(x + 1, pre), seat[pre] = x, dfs(x + 1, pre + 1);
}
inline void solve() {
  read_int(n), read_int(m), read_int(r), read_int(c);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) read_int(a[i][j]);
  dfs(1, 1);
  put_int(ans);
}
}  // namespace BREAD
int main() {
#ifdef LOCAL
#ifdef DATA
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
#endif
  BREAD::solve();
#ifdef DEBUG
#endif
#ifdef LOCAL
#ifdef HAND
  system("pause");
#endif
#endif
  return 0;
}

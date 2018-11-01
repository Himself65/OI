#define LOCAL  // For Windows
#define DEBUG
#define DATA
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
const int maxn = 1e6 + 5;
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
struct EDGE {
  int to, next;
} e[maxn];
int n, q, tot, deep, head[maxn], d[maxn], dis[maxn], f[maxn][32];
inline void add_edge(int u, int v) {
  e[++tot].to = v, e[tot].next = head[u], head[u] = tot;
}
inline void dfs(int x) {
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;  // 下一个点位置
    if (d[y]) continue;
    d[y] = d[x] + 1, dis[y] = dis[x] + 1, f[y][0] = x;
    for (int j = 1; j <= deep; ++j) f[y][j] = f[f[y][j - 1]][j - 1];
    dfs(y);
  }
}
inline void swap(int &x, int &y) {
  register int t = x;
  x = y, y = t;
}
inline int lca(int x, int y) {
  if (d[x] > d[y]) swap(x, y);
  for (int i = deep; i >= 0; --i)
    if (d[f[y][i]] >= d[x]) y = f[y][i];
  if (x == y) return x;
  for (int i = deep; i >= 0; --i)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
inline int dist(int x, int y) { return dis[x] + dis[y] - 2 * dis[lca(x, y)]; }
inline void solve() {
  read_int(n), read_int(q);
  deep = (int)log2(n) + 1;
  for (int i = 2; i <= n; ++i) {
    int u, v;
    read_int(u), read_int(v);
    add_edge(u, v), add_edge(v, u);
  }
  d[1] = 1, dfs(1);
  for (int i = 1; i <= q; ++i) {
    int a, b, c, d;
    read_int(a), read_int(b), read_int(c), read_int(d);
    if (dist(a, b) + dist(c, d) >= dist(a, c) + dist(b, d))
      putchar('Y');
    else
      putchar('N');
    putchar('\n');
  }
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

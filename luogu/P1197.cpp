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
const int maxn = 4e5 + 5;
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
int n, m, k, cnt, tot;
int fa[maxn], head[maxn], a[maxn], ans[maxn];
struct EDGE {
  int to, next;
} e[maxn];
bool vis[maxn];
inline void add(int x, int y) {
  e[++tot].to = y, e[tot].next = head[x], head[x] = tot;
}
inline void init(int n) {
  for (int i = 0; i < n; ++i) fa[i] = i;
}
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) fa[x] = y;
}
inline bool same(int x, int y) { return find(x) == find(y); }
inline void dfs(int x) {
  vis[x] = true;
  for (int i = head[x]; i; i = e[i].next) {
    int to = e[i].to;
    if (!vis[to]) {
      if (!same(x, to)) merge(x, to);
      dfs(to);
    }
  }
}
int x, y;
inline void solve() {
  read_int(n), read_int(m), init(n);
  for (int i = 0; i < m; ++i) read_int(x), read_int(y), add(x, y), add(y, x);
  read_int(k);
  for (int i = 0; i < k; ++i) read_int(a[i]), vis[a[i]] = true;
  for (int i = 0; i < n; ++i)
    if (!vis[i]) cnt++, dfs(i);
  ans[k] = cnt;
  memset(vis, false, sizeof(vis));
  for (int i = 0; i < k; ++i) vis[a[i]] = true;
  for (int i = k - 1; i >= 0; --i) {
    vis[a[i]] = false;
    cnt++;
    for (int j = head[a[i]]; j; j = e[j].next) {
      int to = e[j].to;
      if (!vis[to]) {
        if (!same(a[i], to)) merge(a[i], to), cnt--;
      }
    }
    ans[i] = cnt;
  }
  for (int i = 0; i <= k; ++i) put_int(ans[i]), putchar('\n');
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

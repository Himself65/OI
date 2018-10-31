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
const int maxn = 2e4 + 5;
const int maxm = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD {
int n, m;
template <class T>
inline void read_int(T &x) {
  char ch = getchar();
  int op = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + (ch - '0'), ch = getchar();
  x *= op;
}
struct EDGE {
  int x, y;
  ll v;
} e[maxm];
int fa[maxn], b[maxn];
inline void init(int n) {
  for (register int i = 1; i <= n; ++i) fa[i] = i;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) fa[x] = y;
}
bool same(int x, int y) { return find(x) == find(y); }
inline bool cmp(const EDGE &a, const EDGE &b) { return a.v > b.v; }
inline void solve() {
  read_int(n), read_int(m);
  for (register int i = 1; i <= m; ++i) {
    read_int(e[i].x), read_int(e[i].y), read_int(e[i].v);
#ifdef DEBUG
    printf("index: %d  %d %d %lld \n", i, e[i].x, e[i].y, e[i].v);
#endif
  }
  sort(e + 1, e + 1 + m, cmp), init(n);
  bool tag = true;
  for (register int i = 1; i <= m; ++i) {
    EDGE &t = e[i];
    if (same(t.x, t.y)) {
      printf("%lld\n", t.v), tag = false;
      break;
    } else {
      if (!b[t.x])
        b[t.x] = t.y;
      else
        merge(b[t.x], t.y);
      if (!b[t.y])
        b[t.y] = t.x;
      else
        merge(b[t.y], t.x);
    }
  }
  if (tag) printf("0\n");
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
#ifdef TEST
#endif
#ifdef LOCAL
#ifdef HAND
  system("pause");
#endif
#endif
  return 0;
}

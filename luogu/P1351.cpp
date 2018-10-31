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
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
const int MOD = 10007;
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
  for (register int i = p - 1; i >= 0; --i) putchar(_buf[i]);
}
int n, cnt, w[maxn];
struct EDGE {
  int to, next;
} e[maxn << 1];
int head[maxn];
inline void add_edge(int u, int v) {
  e[++cnt].next = head[u], e[cnt].to = v, head[u] = cnt;
}
int ans1, ans2;
void dfs(int r, int f, int g) {
  int maf = 0, mas = 0, sum = 0, squ = 0;
  for (int i = head[r]; i; i = e[i].next) {
    int v = e[i].to;
    if (v != f) {
      sum = (sum + w[v]) % MOD;
      squ = (squ + w[v] * w[v] % MOD) % MOD;
      if (w[v] > maf)
        mas = maf, maf = w[v];
      else if (w[v] > mas)
        mas = w[v];
      dfs(v, r, f);
    }
  }
  ans1 = max(ans1, max(mas * maf, w[r] * w[g]));
  ans2 = (ans2 + (sum * sum % MOD - squ + MOD) % MOD + w[r] * w[g] * 2 % MOD) %
         MOD;
}
inline void solve() {
  read_int(n);
  for (register int i = 2; i <= n; ++i) {
    int u, v;
    read_int(u), read_int(v);
    add_edge(u, v), add_edge(v, u);
  }
  for (register int i = 1; i <= n; ++i) read_int(w[i]);
#ifdef DEBUG
  for (register int i = 1; i <= n; ++i)
    for (register int j = head[i]; j; j = e[j].next)
      printf("from: "), put_int(i), printf("  to: "), put_int(e[j].to),
          printf("\n");
  for (register int i = 1; i <= n; ++i) put_int(w[i]), putchar(' ');
  putchar('\n');
#endif
  dfs(1, 0, 0), put_int(ans1), putchar(' '), put_int(ans2);
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

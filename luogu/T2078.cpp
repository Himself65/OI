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
int n, k, t[maxn];
inline void change(int *a, int *b) {
  for (int i = 1; i <= n; ++i) t[i] = b[a[i]];
  for (int i = 1; i <= n; ++i) a[i] = t[i];
}
int a[maxn], b[maxn];
inline void solve() {
  read_int(n), read_int(k);
  for (int i = 1; i <= n; ++i) read_int(a[i]), b[i] = i;
  for (; k; k >>= 1, change(a, a))
    if (k & 1) change(b, a);
  for (int i = 1; i <= n; ++i) t[b[i]] = i;
  for (int i = 1; i <= n; ++i) put_int(t[i]), putchar(' ');
  //
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

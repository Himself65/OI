#define LOCAL  // For Windows
#define DEBUG
// #define DATA
#define HAND
#include <algorithm>
#include <cctype>
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
const int maxn = 1e7 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD {
template <class T>
inline void read_int(T& x) {
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
int n, cost[maxn], book[maxn], maxlevel, maxd;
bool ok = true;
ll a, b, d, x, y;
void exgcd(int A, int B, ll& D, ll& X, ll& Y) {
  if (!B)
    D = A, X = 1, Y = 0;
  else
    exgcd(B, A % B, D, Y, X), Y = Y - (A / B) * X;
}
inline int f(int x) {
  if (book[x]) {
    book[x]--;
    return 1;
  }
  int p = f(x - 1), q = f(x - 1);
  maxlevel += p + q;
  return ((max(p, q) << 1) | 1);
}
inline void solve() {
  read_int(n);
  for (int i = 1; i <= n; ++i) {
    int t;
    read_int(t);
    maxd = max(maxd, t);
    cost[t]++, book[t]++;
  }
  for (int i = 1; i <= maxd; ++i) {
    cost[i + 1] = cost[i + 1] + (cost[i] / 2), cost[i] %= 2;
    if (cost[i + 1]) maxd = max(maxd, i + 1);
  }
  f(maxd);
  exgcd(maxd, maxlevel, d, x, y);
  if (d != 1)
    put_int(-1);
  else {
    x = (x % maxlevel + maxlevel) % maxlevel;
    put_int(x);
  }
}
}  // namespace BREAD
int main() {
  BREAD::solve();
#ifdef LOCAL
#ifdef HAND
  system("pause");
#endif
#endif
  return 0;
}

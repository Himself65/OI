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
  for (register int i = p - 1; i >= 0; --i) putchar(_buf[i]);
}
inline ll mul_mod(ll a, ll b, ll mod) { return (a * b) % mod; }
inline ll pow_mod(ll x, ll p, ll mod) {
  ll ans = 1;
  while (p) {
    if (p & 1) ans = mul_mod(ans, x, mod);
    x = mul_mod(x, x, mod), p >>= 1;
  }
  return ans % mod;
}
ll n, m, p;
inline void solve() {
  read_int(n), read_int(m), read_int(p);
  put_int(pow_mod(n, p, m));
  putchar('\n');
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

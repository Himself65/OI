#include <algorithm>
#include <cstdio>
#include <iostream>
#define DEBUG
using namespace std;
#define INIT_CIN               \
  ios::sync_with_stdio(false); \
  cin.tie(0);
typedef long long ll;
const int maxn = 5e5 + 5;
#define lowbit(x) (x & -(x))
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
int n, x, tot;
struct BIT {
  int value[maxn];
  void add(int x) {  // value[x] += 1
    while (x < n) value[x]++, x += lowbit(x);
  }
  int sum(int x) {
    int ans = 0;
    while (x) ans += value[x], x -= lowbit(x);
    return ans;
  }
} t;
int a[maxn], b[maxn], c[maxn];
inline bool cmp(int _x, int _y) { return a[_x] > a[_y]; }
ll ans;
int main() {
  read_int(n);
  for (int i = 1; i <= n; ++i) read_int(a[i]), b[i] = i;
  sort(b + 1, b + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) {
    if (i > 1 && a[b[i]] == a[b[i - 1]])
      c[b[i]] = c[b[i - 1]];
    else
      c[b[i]] = ++tot;
  }
  for (int i = 1; i <= n; ++i) {
    t.add(c[i]);
    ans += t.sum(c[i] - 1);
  }
  put_int(ans);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;
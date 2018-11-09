#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
template <typename T>
void read_int(T &x) {
  char ch = getchar();
  int op = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  x = 0;
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= op;
}
template <typename T>
void put_int(T x) {
  static char _buf[1000];
  int _cnt = 0;
  if (x < 0) putchar('-'), x = -x;
  do
    _buf[_cnt++] = (x % 10) + '0', x /= 10;
  while (x);
  for (register int i = _cnt - 1; i >= 0; --i) putchar(_buf[i]);
}
const int maxn = 1e5 + 5;
int MOD;
int n, m, tot;
ll a[maxn];
#define LSON(p) (p << 1)
#define RSON(p) (p << 1 | 1)
struct NODE {
  ll value, mul, add;
  NODE() : value(0), mul(1), add(0) {}
} node[maxn << 2];
void build(int l, int r, int p) {
  if (l == r) {
    node[p].value = a[l];
  } else {
    int mid = (l + r) >> 1;
    build(l, mid, LSON(p)), build(mid + 1, r, RSON(p));
    node[p].value = node[LSON(p)].value + node[RSON(p)].value;
  }
  node[p].value %= MOD;
}
void push_down(int l, int r, int p) {
  int mid = (l + r) >> 1;
  NODE &ls = node[LSON(p)], &rs = node[RSON(p)], &np = node[p];
  ls.value = (ls.value * np.mul + np.add * (mid - l + 1)) % MOD;
  rs.value = (rs.value * np.mul + np.add * (r - mid)) % MOD;
  // push_down mul
  ls.mul = (ls.mul * np.mul) % MOD;
  rs.mul = (rs.mul * np.mul) % MOD;
  // push_down add
  ls.add = (ls.add * np.mul + np.add) % MOD;
  rs.add = (rs.add * np.mul + np.add) % MOD;
  np.mul = 1, np.add = 0;
}
void update1(int p, int nl, int nr, int l, int r, int k) {
  if (r < nl || nr < l)  // out of range
    return;
  NODE &np = node[p];
  if (l <= nl && nr <= r) {
    np.value = (np.value * k) % MOD;
    np.mul = (np.mul * k) % MOD;
    np.add = (np.add * k) % MOD;
    return;
  }
  NODE &rs = node[RSON(p)], &ls = node[LSON(p)];
  push_down(nl, nr, p);
  int mid = (nl + nr) >> 1;
  update1(LSON(p), nl, mid, l, r, k);
  update1(RSON(p), mid + 1, nr, l, r, k);
  np.value = (ls.value + rs.value) % MOD;
}
void update2(int p, int nl, int nr, int l, int r, int k) {
  if (r < nl || nr < l)  // out of range
    return;
  NODE &np = node[p];
  if (l <= nl && nr <= r) {
    np.add = (np.add + k) % MOD;
    np.value = (np.value + k * (nr - nl + 1)) % MOD;
    return;
  }
  NODE &rs = node[RSON(p)], &ls = node[LSON(p)];
  push_down(nl, nr, p);
  int mid = (nl + nr) >> 1;
  update2(LSON(p), nl, mid, l, r, k);
  update2(RSON(p), mid + 1, nr, l, r, k);
  np.value = (ls.value + rs.value) % MOD;
}
ll query(int p, int nl, int nr, int l, int r) {
  if (r < nl || nr < l)  // out of range
    return 0;
  NODE &np = node[p];
  if (l <= nl && nr <= r) return np.value;
  push_down(nl, nr, p);
  int mid = (nl + nr) >> 1;
  return (query(LSON(p), nl, mid, l, r) + query(RSON(p), mid + 1, nr, l, r)) %
         MOD;
}
int main() {
  read_int(n), read_int(m), read_int(MOD);
  for (int i = 1; i <= n; ++i) read_int(a[i]);
  build(1, n, 1);
  for (int i = 1; i <= m; ++i) {
    int x, y, k, op;
    read_int(op), read_int(x), read_int(y);
    if (op == 1)
      read_int(k), update1(1, 1, n, x, y, k);
    else if (op == 2)
      read_int(k), update2(1, 1, n, x, y, k);
    else
      put_int(query(1, 1, n, x, y)), putchar('\n');
  }
#ifdef LOCAL
  system("pause");
#endif
  return 0;
}
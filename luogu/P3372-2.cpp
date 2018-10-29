#define LOCAL
#define HAND
#define DATA
#define DEBUG
#include <cstdio>
#include <iostream>
typedef long long ll;
const int maxn = 1e5 + 5;
int n, m, x, y, k;
ll a[maxn], ans[maxn << 2], tag[maxn << 2];
// data
template <typename T>
T max(const T, const T);
template <typename T>
T min(const T, const T);
//
void init(ll);
void pushup(ll);
void pushdown(ll, ll, ll);
void build(ll, ll, ll);
ll query(ll, ll, ll, ll, ll);
void update(ll, ll, ll, ll, ll, ll);
int main(int argc, char const *argv[]) {
  scanf("%d%d", &n, &m);
  for (register ll i = 1; i <= n; i++) scanf("%lld", a + i);
  build(1, n, 1);
  for (register ll i = 1; i <= m; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &x, &y, &k);
      update(1, n, 1, x, y, k);
    } else {
      scanf("%d%d", &x, &y);
      printf("%lld\n", query(1, n, 1, x, y));
    }
  }
#ifdef LOCAL
#ifdef HAND
  system("pause");
#endif
#endif
  return 0;
}
template <typename T>
T max(const T a, const T b) {
  return a > b ? a : b;
}
template <typename T>
T min(const T a, const T b) {
  return a < b ? a : b;
}
#define LSON(x) (x << 1)
#define RSON(x) (x << 1 | 1)
inline void init(ll p) { tag[p] = 0; }
inline void pushup(ll p) { ans[p] = ans[LSON(p)] + ans[RSON(p)]; }
inline void f(ll l, ll r, ll p, ll k) {
  tag[p] += k, ans[p] += k * (r - l + 1);
}
inline void pushdown(ll l, ll r, ll p) {
  ll mid = (l + r) >> 1;
  f(l, mid, LSON(p), tag[p]), f(mid + 1, r, RSON(p), tag[p]);
  tag[p] = 0;
}
void build(ll l, ll r, ll p) {
  init(p);
  if (l == r) {
    ans[p] = a[l];
  } else {
    ll mid = (l + r) >> 1;
    build(l, mid, LSON(p)), build(mid + 1, r, RSON(p));
    pushup(p);
  }
}
ll query(ll l, ll r, ll p, ll qx, ll qy) {
  ll res = 0;
  if (qx <= l && r <= qy) return ans[p];
  ll mid = (l + r) >> 1;
  pushdown(l, r, p);
  if (qx <= mid) res += query(l, mid, LSON(p), qx, qy);
  if (qy > mid) res += query(mid + 1, r, RSON(p), qx, qy);
  return res;
}
void update(ll l, ll r, ll p, ll nl, ll nr, ll k) {
  if (nl <= l && r <= nr)
    f(l, r, p, k);
  else {
    pushdown(l, r, p);
    ll mid = (l + r) >> 1;
    if (nl <= mid) update(l, mid, LSON(p), nl, nr, k);
    if (nr > mid) update(mid + 1, r, RSON(p), nl, nr, k);
    pushup(p);
  }
}
#undef LSON
#undef RSON
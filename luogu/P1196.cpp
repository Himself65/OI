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
const int maxn = 3e4 + 5;
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
inline void read_char(T &c) {
  char ch = getchar();
  while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
    ch = getchar();
  c = ch;
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
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
int T;
int fa[maxn], que[maxn], num[maxn];
inline void init() {
  for (int i = 1; i <= maxn; ++i) fa[i] = i, num[i] = 1;
}
inline int find(int x) {
  if (fa[x] == x) return x;
  int fax = find(fa[x]);
  que[x] += que[fa[x]];
  return fa[x] = fax;
}
inline void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) fa[x] = y, que[x] += num[y], num[y] += num[x], num[x] = 0;
}
inline void solve() {
  read_int(T), init();
  while (T--) {
    char c;
    int i, j;
    read_char(c), read_int(i), read_int(j);
    int fx = find(i), fy = find(j);
    if (c == 'M')
      merge(i, j);
    else
      fx != fy ? put_int(-1) : (void)printf("%d", abs(que[i] - que[j]) - 1),
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

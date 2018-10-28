#define LOCAL  // For Windows
#define TEST
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
const int maxn = 1e6 + 5;
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
inline void solve() {}
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

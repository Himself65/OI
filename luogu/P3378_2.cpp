#define LOCAL  // For Windows
#define DEBUG
// #define DATA
#define HAND
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
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
const int maxn = 2e6 + 5;
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
int n;
int heap[maxn], sz = 0;
void push(int x) {
  int i = sz++;
  while (i > 0) {
    int father = (i - 1) >> 1;
    if (heap[father] <= x) break;        // 找到位置
    heap[i] = heap[father], i = father;  // 向上递推
  }
  heap[i] = x;
}
int pop() {
  int ret = heap[0];
  int x = heap[--sz];
  int i = 0;
  while ((i << 1) + 1 < sz) {
    int a = (i << 1) + 1, b = (i << 1) + 2;
    if (b < sz && heap[b] < heap[a]) a = b;
    if (heap[a] >= x) break;
    heap[i] = heap[a], i = a;
  }
  heap[i] = x;
  return ret;
}
int top() { return heap[0]; }
inline void solve() {
  //
  read_int(n);
  for (int i = 1; i <= n; ++i) {
    int op, x;
    read_int(op);
    if (op == 1)
      read_int(x), push(x);
    else if (op == 2)
      printf("%d\n", top());
    else {
      pop();
#ifdef DEBUG
      printf("top now is: %d  size: %d\n", top(), sz);
#endif
    }
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

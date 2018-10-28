#define LOCAL  // For Windows
// #define TEST
#define DATA
// #define HAND
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
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
const int maxn = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD {
int n, complex;
string op, code[maxn];
struct Event {
  char var;
  int complex;
};
stack<Event> sk;
map<char, bool> mp;
int T;
inline int read(const string s, int pos) {
  // 读取两个变量，获得复杂度
  char ch = s[pos++];
  int temp = 0, a, b;
  while (ch == ' ') ch = s[pos++];
  while ((ch >= '0' && ch <= '9') || ch == 'n')
    if (ch == 'n') {
      temp = INF;
      pos++;
      break;
    } else
      temp = temp * 10 + (ch - '0'), ch = s[pos++];
  a = temp;
  temp = 0;
  ch = s[pos++];
  while (ch == ' ') ch = s[pos++];
  while ((ch >= '0' && ch <= '9') || ch == 'n')
    if (ch == 'n') {
      temp = INF;
      pos++;
      break;
    } else
      temp = temp * 10 + (ch - '0'), ch = s[pos++];
  b = temp;
#ifdef TEST
  printf("DEBUG: from: %d  to: %d\n", a, b);
#endif
  return (b - a < 0 ? -1 : (b == INF && a != INF ? 1 : 0));
}
inline void solve() {
  cin >> T;
  while (T--) {
    cin >> n, getline(cin, op);
    // clean
    while (!sk.empty()) sk.pop();
    int dph = 0;
    bool fail = false;
#ifdef TEST
    printf("DEBUG: op[3]: %c\n", op[3]);
#endif
    for (register int i = 1; i <= n; i++) getline(cin, code[i]);
    if (n == 1) {
      printf("ERR\n");
      continue;
    }
    if (op[3] == '1')  // 求得复杂度
      complex = 0;
    else {
      int temp = 0, pos = 4;
      char ch = op[pos];
      while (ch < '0' || ch > '9') ch = op[++pos];
      while (ch >= '0' && ch <= '9')
        temp = temp * 10 + (ch - '0'), ch = op[++pos];
      complex = temp;
    }
#ifdef TEST
    printf("DEBUG: O(%d)\n", complex);
#endif
    int max_cplx = 0, now_cplx = 0;
    bool tag = false;
    for (register int i = 1; i <= n; i++) {
      if (fail) {
#ifdef TEST
        printf("DEBUG: ERR on program: %d ,line: %d   \n", T, i);
#endif
        break;
      }
      if (code[i][0] == 'F') {
        dph++;
        char var = code[i][2];
        int cplx = read(code[i], 3);
        if (mp.count(var))
          fail = true;
        else {
          mp[var] = 1;
          sk.push((Event){var, cplx == -1 ? -1 : cplx + now_cplx}),
              now_cplx += cplx;
          if (cplx == -1) tag = true;
          if (!tag) max_cplx = max(max_cplx, now_cplx);
        }
#ifdef TEST
        printf(
            "DEBUG: F on program: %d ,line: %d  var: %c  complex: %d  "
            "max_complex: %d  "
            "now_complex:%d \n",
            T, i, var, cplx, max_cplx, now_cplx);
#endif
      } else if (code[i][0] == 'E') {
        dph--;
        if (sk.empty() || dph < 0) {
#ifdef TEST
          printf("DEBUG: ERR on program: %d ,line: %d  \n", T, i);
#endif
          fail = true;
        } else {
          Event &eve = sk.top();
          sk.pop();
          int cplx = eve.complex;
          char ch = eve.var;
          mp.erase(ch);
          if (cplx == -1)  // 循环无法进入
            now_cplx = 0, tag = false;
          else
            now_cplx = max(0, now_cplx - 1);
#ifdef TEST
          printf(
              "DEBUG: E on program: %d ,line: %d  complex: %d  "
              "max_complex: %d  "
              "now_complex:%d \n",
              T, i, cplx, max_cplx, now_cplx);
#endif
        }
      }
    }
#ifdef TEST
    printf("DEBUG: FINALLY on program: %d  max_cplex: %d  now_complex: %d\n", T,
           max_cplx, now_cplx);
#endif
#ifdef TEST
    printf("DEBUG: ERR on program: %d sk: %s,\n", T,
           sk.empty() ? "empty" : "fill");

#endif
    if (!sk.empty() || fail)
      printf("ERR\n");
    else if (max_cplx == complex)
      printf("Yes\n");
    else if (max_cplx != complex)
      printf("No\n");
    mp.erase(mp.begin(), mp.end());
  }
}
}  // namespace BREAD
int main() {
#ifdef LOCAL
#ifdef DATA
  freopen("in4.txt", "r", stdin);
  freopen("out4.txt", "w", stdout);
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
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
unsigned int count[1 << 7];

int main() {
  char str[256];
  int n;
  scanf("%s %d", str, &n);
  unsigned int maxn = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
    count[str[i]]++;
    if (maxn = MAX(maxn, count[str[i]]) == n) {
      for (int j = 0; j < 1 << 7; ++j)
        if (count[j] == n) {
          printf("%c", str[i]);
          goto end;
        }
    }
  }
  end:
  return 0;
}

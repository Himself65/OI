#include <stdio.h>
unsigned int str_len(const char *p) {
  unsigned int sz = 0;
  while (*(p++) != '\0')
    sz++;
  return sz;
}
void fun(char *x, int begin, int end) {
  char c;
  if (begin >= end)
    return;
  c = *(x + begin);
  *(x + begin) = *(x + end);
  *(x + end) = c;

  fun(x, ++begin, --end);
}
int main() {
  char str[256];
  scanf("%s", str);
  fun(str, 0, str_len(str) - 1);
  printf("%s", str);
  return 0;
}

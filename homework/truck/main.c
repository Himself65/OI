#include <stdio.h>
#include <string.h>
typedef unsigned int u_int;
int is_sqr[10005];
u_int first_two_digits(u_int num) {
  while (num >= 100)
    num /= 10;
  return num;
}
u_int last_two_digits(u_int num) {
  return ((num % 10) + ((num / 10) % 10) * 10);
}
int main() {
  memset(is_sqr, 0, 10005);
  for (int i = 1; i < 99; ++i) {
    is_sqr[i * i] = 1;
  }
  u_int result = 1000;
  for (;; result++) {
    u_int fst = first_two_digits(result);
    u_int lst = last_two_digits(result);
    if ((u_int) (fst / 10) == (fst % 10) && (u_int) (lst / 10) == (lst % 10) && is_sqr[result] == 1) {
      printf("%u\n", result);
      break;
    }
  }
  return 0;
}

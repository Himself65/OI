#include <stdio.h>
#include <stddef.h>

int main() {
  char x[6];
  scanf("%s", x);
  for (size_t i = 0; x[i] != '\0'; i++) {
    x[i] = ((x[i] - '0' + 6) % 8) + '0';
  }
  printf("%s", x);
  return 0;
}

#include <stdio.h>
int month[13] = {
    0,
    31, // 1
    28, // 2: 28 / 29
    31, // 3
    30,
    31, // 5
    30,
    31, // 7
    31, // 8
    30,
    31,
    30,
    31  // 12
};
int is_leap(int year) {
  if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) {
    return 1;
  }
  return 0;
}
int main() {
  int year, mon, day;
  int total = 0;
  printf("Enter \"year:month:day\"\n");
  scanf("%d:%d:%d", &year, &mon, &day);
  if (is_leap(year)) {
    month[2] = 29;
  }
  for (int pos = 1; pos < mon; pos++) {
    total += month[pos];
  }
  printf("total %d days", total + day);
  return 0;
}

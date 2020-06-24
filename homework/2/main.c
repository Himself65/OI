#include <stdio.h>
double a[3][3] = {
    {5.4, 3.2, 8},
    {6, 4, 3.3},
    {7, 3, 1.3}
};
int main() {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      a[i][j] /= a[i][i];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j)
      printf("%.1lf ", a[i][j]);
    printf("\n");
  }
  return 0;
}

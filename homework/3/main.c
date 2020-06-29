#include <stdio.h>
#define ROW 3
#define COL 4
int matrix[ROW][COL];
void _swap(int *a, int *b) {
  int c = *a;
  *a = *b, *b = c;
}

int main() {
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j)
      scanf("%d", &matrix[i][j]);
    int maxp = 0;
    for (int j = 0; j < COL; ++j)
      if (matrix[i][j] > matrix[i][0] && matrix[i][j] > matrix[i][maxp]) maxp = j;
    _swap(&matrix[i][0], &matrix[i][maxp]);
  }
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
  return 0;
}

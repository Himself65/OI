#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_N (100)
typedef struct {
  int id;
  int score;
} Student;
Student students[MAX_N];

int main() {
  int id, score;
  size_t pos = 0;
  printf("Enter the array of {id} {score} \nEnd with -1 -1 to stop\n");
  while (scanf("%d %d", &id, &score) != EOF) {
    if (id == -1) break;
    students[pos].id = id;
    students[pos++].score = score;
  }
  long long average = 0;
  for (size_t i = 0; i < pos; i++)
    average += students[i].score;
  average /= pos;
  for (size_t i = 0; i < pos; i++)
    if (students[i].score > average)
      printf("student (ID: %d) score higher than average.\n", students[i].score);
  return 0;
}

#include <stdio.h>
int res = 0x3f3f;
int x, y, z;
int main() {
  for (int kX = 1; kX <= 40; ++kX) {
    for (int kZ = 1; kZ <= 10; ++kZ) {
      const int sum = 5 * kX + 21 * kZ;
      if (sum != 200) continue;
      const int kY = (200 - 5 * kX - kZ) / 2;
      if (res > kX + kY + kZ)
        res = kX + kY + kZ, x = kX, y = kY, z = kZ;
    }
  }
  printf("%d %d %d\n", x, y, z);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "CobraBib.h"
#include <string.h>

int main() {
  int x, y, pos[5], i =0;

  scanf("%d %d", &x, &y);
  memset(pos, (y * 10 + x), sizeof(pos));

  maps(pos);

  menu(pos);
  return 0;
}

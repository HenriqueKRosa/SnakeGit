#include <stdlib.h>
#include <stdio.h>
#include "include/CobraBib.h"
#include <string.h>

int main() {
  int pos[5], map;
  
  memset(pos, 0, sizeof(pos));
  printf("Selecione o mapa:(Apenas 1 no momento)\n");
  scanf("%d", &map);
  pos[0] = 54;

  maps(pos);

  menu(pos);
  printf("GAME OVER\n");
  return 0;
}

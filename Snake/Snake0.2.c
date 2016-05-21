#include <stdlib.h>
#include <stdio.h>
#include "CobraBib.h"
#include <string.h>

int main() {
  int pos[5], map;
  
  memset(pos, 0, sizeof(pos));
  printf("Selecione o mapa:(Apenas 1 no momento)\n");
  scanf("%d", &map);
  pos[0] = 55;

  maps(pos);

  menu(pos);
  //system("clear");
  printf("GAME OVER\n");
  return 0;
}

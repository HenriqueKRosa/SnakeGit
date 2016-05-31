#include <stdlib.h>
#include <stdio.h>
#include "include/CobraBib.h"
#include <string.h>
int nivelId;
char nivel[220];

int main() 
{
	int pos[5];
	
	memset(pos, 0, sizeof(pos));
	
	printf("Selecione o mapa:(Apenas 0||1 no momento)\n");
	scanf("%d", &nivelId);
	pos[0] = 54;
	
	CarregaNivel();
	ImprimeMapa(pos);
	
	Menu(pos);
	printf("GAME OVER\n");
	
	return 0;
}

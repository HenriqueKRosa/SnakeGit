#include <stdlib.h>
#include <stdio.h>
#include "include/CobraBib.h"
#include "include/MenuBib.h"
#include <string.h>
int nivelId;
char nivel[220];

int main() 
{
	Cobra *head;

	printf("Selecione o mapa:(Apenas 0||1 no momento)\n");
	scanf("%d", &nivelId);

	CarregaNivel();
	head = IniciaCobra();
	ImprimeMapa(head);
	
	Jogo(head);
	printf("GAME OVER\n");

	return 0;
}

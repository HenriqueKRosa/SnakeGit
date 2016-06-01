#include <stdlib.h>
#include <stdio.h>
#include "include/CobraBib.h"
#include <string.h>
int nivelId = 0;
char nivel[220];

int main() 
{
	Cobra *condutor, *head, *cobra1, *cobra2, *cobra3;

	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));
	cobra2 = malloc(sizeof(Cobra));
	cobra3 = malloc(sizeof(Cobra));

	head->pos = 54;
	head->next = cobra1;
	cobra1->pos = 0;
	cobra1->next = cobra2;
	cobra2->pos = 0;
	cobra2->next = cobra3;
	cobra3->pos = 0;
	cobra3->next = 0;

	condutor = head;
	//printf("Selecione o mapa:(Apenas 0||1 no momento)\n");
	//scanf("%d", &nivelId);

	CarregaNivel();
	ImprimeMapa(head, condutor);
	/*
	Menu(head, condutor);
	printf("GAME OVER\n");
	*/

	return 0;
}

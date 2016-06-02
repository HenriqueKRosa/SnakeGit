#include <stdlib.h>
#include <stdio.h>
#include "include/CobraBib.h"
#include "include/MenuBib.h"
#include <string.h>
int nivelId;
char nivel[220];

int main() 
{
	Cobra *head, *cobra1, *cobra2, *cobra3, *cobra4;
	int op;

	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));
	cobra2 = malloc(sizeof(Cobra));
	cobra3 = malloc(sizeof(Cobra));
	cobra4 = malloc(sizeof(Cobra));

	head->pos = 54;
	head->next = cobra1;
	cobra1->pos = 55;
	cobra1->next = cobra2;
	cobra2->pos = 56;
	cobra2->next = cobra3;
	cobra3->pos = 57;
	cobra3->next = cobra4;
	cobra4->pos = 58;
	cobra4->next = 0;

		printf("Selecione o mapa:(Apenas 0||1 no momento)\n");
		scanf("%d", &nivelId);

		CarregaNivel();
		ImprimeMapa(head);
	
		Jogo(head);
		printf("GAME OVER\n");

	return 0;
}

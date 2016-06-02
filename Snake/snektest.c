#include <stdlib.h>
#include <stdio.h>
#include "include/CobraBib.h"

int nivelId = 0;
char nivel[110];

int main()
{
	Cobra *condutor, *head, *cobra1;

	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));

	head->pos = 54;
	head->next = cobra1;

	cobra1->pos = 55;
	cobra1->next = NULL;

	condutor = head;

	CarregaNivel();
	ImprimeMapa(head, condutor);

return 0;
}


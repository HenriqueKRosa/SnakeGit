#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/CobraBib.h"

int nivelId = 0;
char nivel[110];

int main()
{
	printf("a");
	Cobra *root, *bora, *cond, *bhir;

	root = malloc(sizeof(Cobra));
	bora = malloc(sizeof(Cobra));	
	bhir = malloc(sizeof(Cobra));

	root->pos = 54;
	root->next = bora;
	bora->pos = 55;
	bora->next = bhir;
	bhir->pos = 56;
	bhir->next = 0;

	cond = root;
/*	if(cond != 0) {
		while(cond->next != NULL)
		{
			printf("%d\n", cond->pos);
			cond = cond->next;
		}
	}*/
	CarregaNivel();
	ImprimeMapa(root, cond);

return 0;
}

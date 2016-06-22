#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "../include/CobraBib.h"
#include "../include/NivelBib.h"
#include "../include/PlayerBib.h"
#include "../include/MenuBib.h"
int nivelId = 0;
char nivel[500];
int colunas;

int main()
{
	int isGameOver = 0, quit = 0;
	Cobra *head, *cobra1, *cobra2, *cobra3;
	
	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));
	cobra2 = malloc(sizeof(Cobra));
	cobra3 = malloc(sizeof(Cobra));
	
	head->pos = 55;
	head->next = cobra1;
	cobra1->pos = 0;
	cobra1->next = cobra2;
	cobra2->pos = 0;
	cobra2->next = cobra3;
	cobra3->pos = 0;
	cobra3->next = NULL;
	
	CarregaNivel();
	
	puts(nivel);
	return 0;
}

int main1()
{
		int op;
		Cobra *head;
		
		head = malloc(sizeof(Cobra));
		
		Inicio:
		Print_Title();
		op = Menu();
		
		switch(op)
		{
				case 1:
					Jogo(head);
					break;
				case 2:
					Stage_selection();
					break;
				case 3:
					puts("Nao implementado ainda!");
					getch();
					goto Inicio;
					break;
				case 4:
					return 0;
		}
		
		getch();
		return 0;
}
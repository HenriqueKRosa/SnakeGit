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

/*int main2()
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
	ImprimeMapa(head);
	
	do
	{
		quit = Movimentacao(head);
		system("cls");
		isGameOver = ImprimeMapa(head);
	}while((isGameOver != 1) && (quit != 1));
	puts("Game over");
	getch();
	return 0;
}*/

int main()
{
		int op;
			
		Inicio:
		Print_Title();
		op = Menu();
		
		switch(op)
		{
				case 1:
					system("cls");
					Jogo();
					puts("Press any key to return to main menu.");
					getch();
					goto Inicio;
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
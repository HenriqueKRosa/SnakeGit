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
	Cobra *head, *cobra1, *cobra2;
	
	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));
	cobra2 = malloc(sizeof(Cobra));
	
	head->pos = 55; //Cabeça
	head->next = cobra1;
	
	cobra1->pos = 0; //p1 corpo
	cobra1->next = cobra2;
	
	cobra2->pos = 0; //p2 corpo
	cobra2->next = NULL;
	
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
}

int main2()
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
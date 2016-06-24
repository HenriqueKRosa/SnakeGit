#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "../include/CobraBib.h"
#include "../include/NivelBib.h"
#include "../include/PlayerBib.h"
#include "../include/MenuBib.h"
int nivelId = 1;
char nivel[500];
int colunas = 0;

int main2()
{
	int isGameOver = 0, quit = 0;
	char comando = 'I';
	Cobra *head, *cobra1, *cobra2;
	
	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));
	cobra2 = malloc(sizeof(Cobra));
	
	head->pos = 55;
	head->next = cobra1;
	cobra1->pos = 0;
	cobra1->next = cobra2;
	cobra2->pos = 0;
	cobra2->next = NULL;
	
	CarregaNivel();
	ImprimeMapa(head, comando);
	
	do
	{
		quit = Movimentacao(head, &comando);
		system("cls");
		isGameOver = ImprimeMapa(head, comando);
	}while((isGameOver != 1) && (quit != 1));
	puts("Game over");
	getch();
	return 0;
}

int main() //Jogo temporário
{
		int op, op1, win;
			
		Inicio:
		Print_Title();
		op = Menu();
		
		Opcao:
		switch(op)
		{
				case 1:
					system("cls");
					win = Jogo();
					if(win == 1)
					{
						nivelId++;
						goto Opcao;
					}
					puts("Press any key to return to main menu.");
					getch();
					goto Inicio;
					break;
				case 2:
					op1 = Stage_selection();
					switch(op1)
					{
						case 0:
							nivelId = 0;
							op = 1;
							goto Opcao;
							break;
						case 1:
							nivelId = 1;
							op = 1;
							goto Opcao;
							break;
						case 2:
							nivelId = 2;
							op = 1;
							goto Opcao;
							break;
						case 3:
							goto Inicio;
							break;
					}
					break;
				case 3:
					puts("Nao implementado ainda!");
					getch();
					goto Inicio;
					break;
				case 4:
					return 0;
		}
}
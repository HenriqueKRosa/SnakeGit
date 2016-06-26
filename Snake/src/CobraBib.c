#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "../include/PlayerBib.h"
#include "../include/CobraBib.h"
#include "../include/MenuBib.h"
#include "../include/NivelBib.h"
#include <stdlib.h>
#include<time.h>
#include<windows.h>
extern char nivel[500];
extern int nivelId;
extern int colunas;

void Movimentacao(Cobra *head, char comando) //Move de acordo com o comando.
{
	switch (comando) {
		case 'W':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos - colunas;
			break;
		case 'S':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos + colunas;
			break;
		case 'A':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos - 1;
			break;
		case 'D':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos + 1;
			break;
		/*case '+':
			AumentaCobra(head);
			break;
		case '-':
			DeletaCobra(head);
			break;*/
	}
	Sleep(500);
}

int Pause(char *initcomando, char *lastcomand)
{
		char tecla = 'a';
		int quit;
		
		system("cls");
		printf("%20s\nPress P to unpause.", "GAME PAUSED");

		do
		{
				tecla = getch();
				tecla = toupper(tecla);
		}while((tecla != 'P') && (tecla != 'Q'));

		if(tecla == 'Q')
			quit = 1;
		else
			quit = 0;
		
		*initcomando = *lastcomand;
		
		return quit;
}

int RepeteComando(Cobra *head, char *initcomando, char *lastcomand, Player *AAA)
{
		int quit = 0, ratos, vidas, isValidKey, tam;
		clock_t start, end;
		
		ratos = 2;
		vidas = 1;
		
		isValidKey = ((*initcomando == 'A') || (*initcomando == 'W') || (*initcomando == 'D') || (*initcomando == 'S'));
		tam = GetCobraSize(head);
		
		start = clock();
		if(isValidKey)
		{
			while((!kbhit()) && (quit == 0) && (tam >= 1))
			{
				Movimentacao(head, *initcomando);
				system("cls");
				GUI(*AAA, vidas, ratos);
				quit = ImprimeMapa(head, *initcomando, AAA);
				tam = GetCobraSize(head);
				end = clock();
			}
			if(tam < 1)
				quit = 1;
			if(quit == 0)
			{	
				*lastcomand = *initcomando;
				*initcomando = toupper(getch());
			}
		}
		else if(*initcomando == 'J')
		{
			quit = 2;
		}
		else if(*initcomando == 'Q')
		{
				quit = 3;
		}
		else if(*initcomando == 'P')
		{
				quit = Pause(initcomando,lastcomand);
		}
		else
		{
			while((!kbhit()) && ((quit == 0) && (tam >= 1)))
			{
				Movimentacao(head, *lastcomand);
				system("cls");
				GUI(*AAA, vidas, ratos);
				quit = ImprimeMapa(head, *lastcomand, AAA);
				tam = GetCobraSize(head);
				end = clock();
			}
			if(tam < 1)
				quit = 1;
			if(quit == 0)
			{	
				*initcomando = toupper(getch());
			}
		}
		if(((end - start) / CLOCKS_PER_SEC) > 0.1)
			CriaRato(head);
		
		return quit;
}

void CriaNovaCobra(Cobra *head) //Cria um novo pedaço de snake e o coloca na mesma posição da cabeça.
{
	Cobra *nova;

	nova = malloc(sizeof(Cobra));
	nova->pos = head->pos;
	nova->hasFood = 0;
	nova->next = head->next;
	head->next = nova;
}

void AumentaCobra(Cobra *head) //Quase o mesmo que a função acima, porém a posição do novo pedaço fica na posição 0 para evitar conflitos
{
	Cobra *nova;
	
	nova = malloc(sizeof(Cobra));
	nova->pos = 0;
	nova->hasFood = 0;
	nova->next = head->next;
	head->next = nova;
	nova->next->hasFood = 1;
}

void DeletaCobra(Cobra *head) //Deleta o último elemento da lista de Cobra
{
	Cobra *tmp;

	tmp = head;

	while(tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
}

int GetCobraSize(Cobra *head) //Calcula o tamanho da lista de Cobra
{
		Cobra *tmp;
		int size = 0;
	
		tmp = head;
		
		while(tmp != NULL)
		{
			size++;
			tmp = tmp->next;
		}
		
		return size;
}
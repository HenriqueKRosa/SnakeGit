#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "include/CobraBib.h"
#include <stdlib.h>
extern char nivel[220];
extern int nivelId;

void CarregaNivel()
{
	FILE *mapaArqv;

	if(nivelId == 0)
	{
	 	mapaArqv = fopen("maps/test", "r");
  		fread(nivel, 1, 110, mapaArqv);
		fclose(mapaArqv);
	}

	else if(nivelId == 1)
	{
		mapaArqv = fopen("maps/1", "r");
		fread(nivel, 1, 220, mapaArqv);
		fclose(mapaArqv);
	}
}

int ImprimeMapa(Cobra *head)
{
	int index = 0, isSnake = 0, isGameOver = 0, i, colunas;
	int isPosOfSnake, isNotWall;
	Cobra *condutor;

	condutor = head;	
	colunas = GeraNumColunas();

	while(nivel[index] != '\0')
	{
		for(i = 0; i <= colunas; i++)
		{
			while(condutor->next != NULL)
			{
				isPosOfSnake = (index == condutor->pos);
				isNotWall = (nivel[index] != '#');

				if(isPosOfSnake && isNotWall)
				{
					if (condutor == head)
					{
						printf("@");
						isSnake = 1;
					}
					else if(isSnake != 1)
					{
						printf("*");
						isSnake = 1;
					}
				}
				else if (condutor != head)
				{
					if((head->pos == condutor->pos) && (condutor != head->next))
						isGameOver = 1;
				}
				condutor = condutor->next;
			}
			if((index == head->pos) && (nivel[index] == '#'))
			{
				isGameOver = 1;
			}
			if(isSnake == 0)
			{
				printf("%c", nivel[index]);
			}
			
			index++;
			isSnake = 0;
			condutor = head;
			if(i == colunas)
				printf("\n");
		}
	}
	return isGameOver;
}
	
int GeraNumColunas()
{
	int colunas;

	if(nivelId == 0)
	{
		colunas = 9;
	}
	else if(nivelId == 1)
	{
		colunas = 19;
	}
	
	return colunas;
}

char LeComando()
{
	char comando;

	scanf("%c", &comando);
	comando = toupper(comando);

	return comando;
}

int Movimentacao(Cobra *head)
{
	int quit = 0, colunas, i;

	colunas = GeraNumColunas(nivelId);

	switch (LeComando()) {
		case 'W':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos - colunas - 1;
			break;
		case 'S':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos + colunas + 1;
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
		case '+':
			CriaNovaCobra(head);
			break;
		case '-':
			DeletaCobra(head);
			break;
		case 'Q':
			quit = 1;
			break;
	}
	return quit;
}

void CriaNovaCobra(Cobra *head)
{
	Cobra *nova;

	nova = malloc(sizeof(Cobra));
	nova->pos = head->pos;
	nova->next = head->next;
	head->next = nova;
}

void DeletaCobra(Cobra *head)
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

Cobra* IniciaCobra()
{
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

	return head;
}

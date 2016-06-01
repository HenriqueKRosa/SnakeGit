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

int ImprimeMapa(Cobra *head, Cobra *condutor)
{
	int index = 0, isSnake = 0, isGameOver = 0, i, colunas;
	
	colunas = GeraNumColunas();

	while(nivel[index] != '\0')
	{
		for(i = 0; i <= colunas; i++)
		{
			if(condutor->next != 0)
			while(condutor->next != 0)
			{
				if((index == condutor->pos) && (nivel[index] != '#'))
				{
					if (condutor == head)
					{
						printf("@");
						isSnake = 1;
					}
					
					else
					{
						printf("*");
						isSnake = 1;
					}
				}
				else if((index == head->pos) && (nivel[index] == '#'))
				{
					isGameOver = 1;
				}
				else
				{
					if(head->pos == condutor->pos)
						isGameOver = 1;
				}
				condutor = condutor->next;
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
/*
int Movimentacao(Cobra head)
{
	int quit = 0, colunas, i;
	
	colunas = GeraNumColunas(nivelId);

	switch (LeComando()) {
		case 'W':
			pos[4] = 0;
			
			for(i = 4; i >= 0; i--)
			{
				if (i == 0)
					pos[i] = pos[i] - (colunas + 1);
				else
					pos[i] = pos[i - 1];
			}
			break;
		
		case 'S':
			pos[4] = 0;
			
			for(i = 4; i >= 0; i--)
			{
				if (i == 0)
					pos[i] = pos[i] + (colunas + 1);
				else
					pos[i] = pos[i - 1];
			}
			break;
		
		case 'A':
			pos[4] = 0;
			
			for(i = 4; i >= 0; i--)
			{
				if (i == 0)
					pos[i] = pos[i] - 1;
				else
					pos[i] = pos[i - 1];
			}
			break;
		
		case 'D':
			pos[4] = 0;
			
			for(i = 4; i >= 0; i--)
			{
				if (i == 0)
					pos[i] = pos[i] + 1;
				else
					pos[i] = pos[i - 1];
			}
			break;
		
		case 'Q':
			quit = 1;
			break;
	}
	return quit;
}

void Menu(Cobra *head, Cobra *condutor)
{
	int isGameOver = 0, quit = 0;
	
	CarregaNivel();

	do
	{
		isGameOver = Movimentacao(head);
		system("clear");
		quit = ImprimeMapa(head, condutor);
	}while((isGameOver != 1) && (quit != 1));
}
*/

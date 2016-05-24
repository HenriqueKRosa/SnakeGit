#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "include/CobraBib.h"
#include <stdlib.h>

void CarregaNivel(int nivelId)
{
	FILE *mapaArqv;

	if(nivelId == 0)
	{
		char nivel[110];
	 	mapaArqv = fopen("maps/test", "r");
  		fread(nivel, 1, 110, mapaArqv);
		nivel[110] = nivel[110];
	}

	else if(nivelId == 1)
	{
		char nivel[209];
		mapaArqv = fopen("maps/1", "r");
		fread(nivel, 1, 209, mapaArqv);
		nivel[209] = nivel[209];
	}
}

int ImprimeMapa(int pos[5])
{
	int index = 0, isSnake = 0, isGameOver = 0;
	
	while(nivel[index] != '\0')
	{
		for(i = 0; i <= colunas; i++)
		{
			for(k = 0; k <= 4; k++)
			{
				if((index == pos[k]) && (mapaArqv[index] != '#'))
				{
					if (k == 0)
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
				else if((index == pos[0]) && (mapaArqv[index] == '#'))
				{
					isGameOver = 1;
				}
				if(k > 0)
				{
					if(pos[0] == pos[k])
						isGameOver = 1;
				}
			}
			if(isSnake == 0)
			{
				printf("%c", mapaArqv[index]);
			}
			
			x++;
			isSnake = 0;
			
			if(i == 9)
				printf("\n");
		}
	}
	
	return isGameOver;
}
	
int GeraNumColunas(int nivelId)
{
	if(nivelId == 0)
	{
		int colunas = 9;
	}
	else if(nivelId == 1)
	{
		int colunas = 21;
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

int Movimentacao(int pos[5], int nivelId)
{
	int quit = 0, colunas;
	
	colunas = GeraNumColunas();

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

void Menu(int pos[5])
{
 int isGameOver = 0, quit = 0;
 
 do
 {
	 CarregaNivel();
	 isGameOver = movimentacao(pos);
	 system("clear");
	 quit = maps(pos);
 }while((isGameOver == 1) && (quit == 1));
}

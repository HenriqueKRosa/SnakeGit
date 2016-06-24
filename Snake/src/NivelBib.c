#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../include/CobraBib.h"
#include "../include/PlayerBib.h"
#include "../include/MenuBib.h"
#include "../include/NivelBib.h"
#include <stdlib.h>
extern char nivel[500];
extern int nivelId;
extern int colunas;

void GetLinECol(int *linhas, FILE *mapaArqv) //Lê do arquivo o número de linhas e colunas. Obs: colunas é var global.
{
	char space[2] = " ";
	char *infos;
	char linEcol[7];
	
	fgets(linEcol, 6, mapaArqv);
	infos = strtok(linEcol, space);
	*linhas = atoi(infos);
	
	infos = strtok(NULL, space);
	colunas = atoi(infos);
}

void strcpy2(char *dest, int pos, char *src) //Copia uma string pra dentro de outra a partir da posição "pos".
{
		int i = 0;
		
		do
		{
			dest[pos+i] = src[i];
			i++;
		}while( src[i] != '\0' );		
}

void makeMapa(FILE *mapaArqv, int linhas, char *nivel) //Carrega o mapa "matriz" numa string.
{
	char linha[colunas];
	int pos = 0;
	int i;
	
	fseek(mapaArqv, 8, SEEK_SET);
	for(i = 0; i <= linhas; i++)
	{
		fgets(linha, colunas+1, mapaArqv);
		strcpy2(nivel, pos, linha);
		fseek(mapaArqv, 2, SEEK_CUR);
		pos += colunas;
	}
	fclose(mapaArqv);
}

void CarregaNivel() //Carrega um nível a partir do valor da var global nivelId.
{
	FILE *mapaArqv;
	int linhas;
	
	if(nivelId == 0)
	{
	 	if((mapaArqv = fopen("maps/test.txt", "r")) == NULL)
			perror("NAO VAI DA NAO");
		else
		{
			GetLinECol(&linhas, mapaArqv);
			makeMapa(mapaArqv, linhas, nivel);
		}
	}

	else if(nivelId == 1)
	{
	 	if((mapaArqv = fopen("../maps/1.txt", "r")) == NULL)
			perror("NAO VAI DA NAO");
		else
		{
		GetLinECol(&linhas, mapaArqv);
		makeMapa(mapaArqv, linhas, nivel);
		}
	}
	
	else if(nivelId == 2)
	{
	 	if((mapaArqv = fopen("../maps/2.txt", "r")) == NULL)
			perror("NAO VAI DA NAO");
		else
		{
			GetLinECol(&linhas, mapaArqv);
			makeMapa(mapaArqv, linhas, nivel);
		}
	}
}

int ImprimeMapa(Cobra *head, char comando)
{
	int index = 0, isSnake = 0, isGameOver = 0, i;
	int isPosOfSnake, isNotWall;
	Cobra *condutor;

	condutor = head;

	while(nivel[index] != '\0')
	{
		for(i = 0; i < colunas; i++)
		{
			while(condutor != NULL)
			{
				isPosOfSnake = (index == condutor->pos);
				isNotWall = (nivel[index] != '#');

				if(isPosOfSnake && isNotWall)
				{
					if (condutor == head)
					{
						ImprimeCabeca(comando);
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
			if((index == head->pos) && (nivel[index] == '#')) //Verifica se houve colisão com a parede.
			{
				isGameOver = 1;
			}
			if(isSnake == 0) //Caso não seja Snake, imprime o caracter do mapa.
			{
				printf("%c", nivel[index]);
			}
			
			index++;
			isSnake = 0;
			condutor = head;
			if(i == colunas-1)
				printf("\n");
		}
	}
	return isGameOver;
}

void ImprimeCabeca(char comando)
{
	switch(comando)
	{
		case 'W':
		putch('V');
		break;
		case 'S':
		putch('^');
		break;
		case 'D':
		putch('<');
		break;
		case 'A':
		putch('>');
		break;
		case 'I':
		putch('O');
		break;
	}
}

void Print_Map(char Map_Name[20])
{
    FILE *Map_File;
    char ch;
    char Map_Adress[25] = "maps/";
    strcat(Map_Adress, Map_Name);
    Map_File = fopen(Map_Adress, "r");
    while ( (ch = fgetc(Map_File) ) != EOF) {
		printf("%c",ch);
	}
	fclose(Map_File);
}
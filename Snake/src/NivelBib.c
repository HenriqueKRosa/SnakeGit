#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "include/CobraBib.h"
#include "include/MenuBib.h"
#include "include/NivelBib.h"
#include "include/PlayerBib.h"
#include <stdlib.h>
extern char nivel[500];
extern int nivelId;

void GetLinECol(int *linhas, int *colunas, FILE *mapaArqv)
{
	char space[2] = " ";
	char *infos;
	char linEcol[7];
	
	fgets(linEcol, 6, mapaArqv);
	infos = strtok(linEcol, space);
	*linhas = atoi(infos);
	
	infos = strtok(NULL, space);
	*colunas = atoi(infos);
}

void strcpy2(char *dest, int pos, char *src)
{
		int i = 0;
		
		do
		{
			dest[pos+i] = src[i];
			i++;
		}while( src[i] != '\0' );		
}

void makeMapa(FILE *mapaArqv, int colunas, int linhas, char *nivel)
{
	char linha[colunas];
	int pos = 0;
	int i, where;
	
	fseek(mapaArqv, 8, SEEK_SET);
	for(i = 0; i <= linhas; i++)
	{
		fgets(linha, colunas+1, mapaArqv);
		strcpy2(nivel, pos, linha);
		puts(linha);
		puts(nivel);
		fseek(mapaArqv, 2, SEEK_CUR);
		pos += colunas;
	}
	fclose(mapaArqv);
}


void CarregaNivel()
{
	FILE *mapaArqv;
	int colunas, linhas;
	char *infos;
	char space[2] = " ";
	char linEcol[7];
	
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
	
	else if(nivelId == 2)
	{
		mapaArqv = fopen("maps/2.txt", "r");
		if(!mapaArqv)
			printf("ERRO NO CARREGAMENTO DO NIVEL, REINICIE POR FAVOR!\n");
		else
		{
			GetLinECol(&linhas, &colunas, mapaArqv);
			fclose(mapaArqv);
		}
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
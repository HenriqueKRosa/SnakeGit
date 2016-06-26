#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../include/PlayerBib.h"
#include "../include/CobraBib.h"
#include "../include/MenuBib.h"
#include "../include/NivelBib.h"
#include <stdlib.h>
#include<time.h>
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

void strcpy2(char *dest, int pos, char *src, int *init) //Copia uma string pra dentro de outra a partir da posição "pos".
{
		int i = 0;
		
		do
		{
			dest[pos+i] = src[i];
			if(src[i] == 'O')
			{
				*init = pos+i;
			}
			i++;
		}while( src[i] != '\0' );
}

void makeMapa(FILE *mapaArqv, int linhas, char *nivel, int *init) //Carrega o mapa "matriz" numa string.
{
	char linha[colunas];
	int pos = 0;
	int i;
	
	fseek(mapaArqv, 8, SEEK_SET);
	for(i = 0; i < linhas; i++)
	{
		fgets(linha, colunas+1, mapaArqv);
		strcpy2(nivel, pos, linha, init);
		fseek(mapaArqv, 2, SEEK_CUR);
		pos += colunas;
		if(i == linhas)
			nivel[pos+1] = '\0';
	}
	fclose(mapaArqv);
}

int CarregaNivel() //Carrega um nível a partir do valor da var global nivelId.
{
	FILE *mapaArqv;
	int linhas, init;
	
	if(nivelId == 0)
	{
	 	if((mapaArqv = fopen("maps/test.txt", "r")) == NULL)
			perror("NAO VAI DA NAO");
		else
		{
			GetLinECol(&linhas, mapaArqv);
			makeMapa(mapaArqv, linhas, nivel, &init);
		}
	}

	else if(nivelId == 1)
	{
	 	if((mapaArqv = fopen("maps/1.txt", "r")) == NULL)
			perror("NAO VAI DA NAO");
		else
		{
			GetLinECol(&linhas, mapaArqv);
			makeMapa(mapaArqv, linhas, nivel, &init);
		}
	}
	
	else if(nivelId == 2)
	{
	 	if((mapaArqv = fopen("maps/2.txt", "r")) == NULL)
			perror("NAO VAI DA NAO");
		else
		{
			GetLinECol(&linhas, mapaArqv);
			makeMapa(mapaArqv, linhas, nivel, &init);
		}
	}
	return init;
}

int ImprimeMapa(Cobra *head, char comando, Player *AAA) //Imprime o mapa e retorna se o jogador tomou game over
{
	int index = 0, isSnake = 0, isGameOver = 0, i;
	int isPosOfSnake, isNotWall;
	Cobra *condutor;

	condutor = head;

	while(nivel[index] != '\0') //Gera pseudo-matriz a partir da string do nivel
	{
		for(i = 0; i < colunas; i++)
		{
			while(condutor != NULL) //Percorre a lista de Cobra.
			{
				isPosOfSnake = (index == condutor->pos);
				isNotWall = (nivel[index] != '#');

				if(isPosOfSnake && isNotWall)
				{
					if (condutor == head) //Se é a cabeça, imprime ela ué
					{
						ImprimeCabeca(comando);
						isSnake = 1;
					}
					else if(isSnake != 1) //Caso contrário imprime o corpo (tem que melhorar e botar no modelo da especificação)
					{
						if(condutor->hasFood == 1)
							putch('O');
						else
							putch('-');
						isSnake = 1;
					}
				}
				else if (condutor != head) //Se a parte do corpo não é a cabeça
				{
					if(head->pos == condutor->pos) //Se a cabeça bateu no corpo dá game over
						isGameOver = 1;
				}
				condutor = condutor->next;
			}
			if((index == head->pos) && (nivel[index] == '#')) //Verifica se houve colisão com a parede.
			{
				isGameOver = 1;
			}
			if((index == head->pos) && (nivel[index] == '*')) //Verifica se houve colisão com uma pedra.
			{
				DeletaCobra(head);
			}
			if((index == head->pos) && (nivel[index] == '&')) //Comeu rato?
			{
					AumentaCobra(head);
					nivel[index] = ' ';
					AddScore(AAA);
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
		default:
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

void PosicoesLivres(Cobra* condutor, int* PosLivres, int* PosOcupadas, int NPosOcupadas)                 //Preenche array com as posições livres no mapa.
{
    int PosDaCobra[500], cont = 0, k = 0, j = 0, TamanhoCobra;
    while(condutor != NULL)
    {
        PosDaCobra[cont] = condutor->pos;
        condutor = condutor->next; //Vai pro próximo elemento da lista
        //++;
	}
    TamanhoCobra = cont;
    while(nivel[k] != '\0')
    {
        if(nivel[k] == ' ' && !(IsKPosDoArray(k, PosDaCobra, TamanhoCobra)) && !(IsKPosDoArray(k, PosOcupadas, NPosOcupadas)))
        {
            PosLivres[j] = k;
            j++;
        }
        k++;
    }
}

int IsKPosDoArray(int k, int* ArrayDePosicoes, int TamanhoArray)         //Verifica se um número K é alguma posição da cobra.
{
    int i, boolean = 0;
    for(i = 0; i < TamanhoArray; i++)
    {
        if(k == ArrayDePosicoes[i])
        {
            boolean = 1;
        }
    }
    return boolean;
}

int GetMapEnd()
{
	int index = 0;
	
	while(nivel[index] != '\0')
	{
			index++;
	}

	return index;
}

int GeraRandPos(Cobra *head)
{
		int r;
		int mapMax, isPosOfSnake = 0;
		Cobra *tmp;
		
		tmp = head;
		mapMax = GetMapEnd();
		srand(time(NULL));
		
		do
		{
				r = rand() % mapMax;
				while(tmp != NULL)
				{
					if(r == tmp->pos)
						isPosOfSnake = 1;
					tmp = tmp->next;
				}
		}while( (nivel[r] == '#') || (nivel[r] == '*') || (isPosOfSnake == 1) );
	return r;
}

void CriaRato(Cobra *head)
{
		int pos = GeraRandPos(head);
		
		nivel[pos] = '&';
}
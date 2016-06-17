#include<string.h>
#include<stdio.h>

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

void strcpy2(char nivel[220], int colunas, char linha[colunas])
{
		
}

void makeMapa(FILE *mapaArqv, int *colunas, int *linhas, char nivel[220])
{
	char linha[*colunas];
	int pos = 0;
	int i;
	
	fseek(mapaArqv, 7, SEEK_SET);
	for(i = 0; i <= *linhas; i++)
	{
		fgets(linha, *colunas, mapaArqv);
		printf("%s\n", linha);
		strcpy((nivel+pos), linha);
		pos = pos + *colunas;
		printf("%d, %d", &nivel[pos], pos);
	}
}

int main()
{
	FILE *mapaArqv;
	int colunas, linhas;
	char nivel[220];
	
	mapaArqv = fopen("maps/2.txt", "r");
	if(!mapaArqv)
		printf("ERRO NO CARREGAMENTO DO NIVEL, REINICIE POR FAVOR!\n");
	else
	{
		GetLinECol(&linhas, &colunas, mapaArqv);
	}
	printf("Num Linhas: %d\nNum Cols: %d\n", linhas, colunas);
	
	makeMapa(mapaArqv, &colunas, &linhas, nivel);
	fclose(mapaArqv);
	printf("%s\n", nivel);
	getch();
return 0;
}
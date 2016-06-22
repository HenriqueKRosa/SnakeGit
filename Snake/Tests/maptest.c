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

int main()
{
	FILE *mapaArqv;
	int colunas, linhas;
	char nivel[220];
	
	memset(nivel,0,sizeof(nivel));
	mapaArqv = fopen("maps/2.txt", "r");
	if(!mapaArqv)
		printf("ERRO NO CARREGAMENTO DO NIVEL, REINICIE POR FAVOR!\n");
	else
	{
		GetLinECol(&linhas, &colunas, mapaArqv);
	}
	printf("Num Linhas: %d\nNum Cols: %d\n", linhas, colunas);
	
	makeMapa(mapaArqv, colunas, linhas, nivel);
	
	puts("MAPA:");
	puts(nivel);
	printf("%d\n", strlen(nivel));
	getch();
return 0;
}
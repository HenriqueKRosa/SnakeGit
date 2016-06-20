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

void strcpy2(char *nivel, int pos, char *linha)
{
		int i = 0;
		
		while( linha[i] != '\0' )
		{
			nivel[pos+i] = linha[i];
			i++;
		}		
}

void makeMapa(FILE *mapaArqv, int colunas, int linhas, char nivel[220])
{
	char linha[colunas];
	int pos = 0;
	int i, where;
	
	fseek(mapaArqv, 8, SEEK_SET);
	for(i = 0; i < linhas; i++)
	{
		fseek(mapaArqv,2,SEEK_CUR);
		puts("Antes:");
		where = ftell(mapaArqv);
		printf("%d\n", where);
		fgets(linha, colunas+1, mapaArqv);
		puts("Dps:");
		where = ftell(mapaArqv);
		printf("%d\n", where);
		strcpy2(nivel, pos, linha);
		pos = pos + colunas;
	}
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
	puts("Linhas:");
	makeMapa(mapaArqv, colunas, linhas, nivel);
	fclose(mapaArqv);
	puts("MAPA:");
	printf("%s\n", nivel);
	getch();
return 0;
}
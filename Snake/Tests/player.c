#include <stdio.h>
#include<string.h>

typedef struct Jogador
{
	char nome[20];
	int pontos;
	int ratos;
	int vidas;
} Player;

void GUI(Player AAA)
{
	printf("ID: %20s Pontos: %5d Ratos: %5d/15 Vidas: %5d", AAA.nome, AAA.pontos, AAA.ratos, AAA.vidas);
}

void GetPlayerName(Player* AAA)
{
	char nomeTemp[20];
	
	puts("Enter a Player name: (Less than 20 characters long.)");
	do{
		gets(nomeTemp);
		if(strlen(nomeTemp) > 20)
			puts("Name too long! Try again.");
	}while(strlen(nomeTemp) > 20);
	strcpy(AAA->nome, nomeTemp);
}

int main()
{
	Player AAA;
	char nome[20];
	
	GetPlayerName(&AAA);
	AAA.pontos = 13;
	AAA.ratos = 5;
	AAA.vidas = 1;
	
	GUI(AAA);
	getch();
	return 0;
}
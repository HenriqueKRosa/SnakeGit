#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../include/PlayerBib.h"
#include "../include/CobraBib.h"
#include "../include/MenuBib.h"
#include "../include/NivelBib.h"
#include <stdlib.h>

void GetPlayerName(Player* AAA) //Pega o Id do Jogador e adequa ao padrão do jogo.
{
	char nomeTemp[20];
	
	puts("Enter a Player name: (Less than 20 characters long.)");
	do{
		gets(nomeTemp);
		if(strlen(nomeTemp) > 20)
			puts("Name too long! Try again.");
	}while(strlen(nomeTemp) > 20);
	strcpy(AAA->nome, nomeTemp);
	system("cls");
}
/*
void Save_Score (Player jogador)
{
    int cont = 0;
    int i, j;
    FILE* scoreboard, scoreboardTemp;
    Player jogadorTemp;
    jogadorTemp.pontos = INT_MAX;
    scoreboard = fopen("scoreboard.bin", "rb+");
    scoreboardTemp = fopen("scoreboardTemp.bin", "wb+");
    while((jogadorTemp.pontos > jogador.pontos) && (cont < 15))
    {
        cont++;
        fread(&jogadorTemp, sizeof(jogador), 1, scoreboard);
    }
    if(jogadorTemp.pontos <= jogador.pontos)
    {
        rewind(scoreboard);
        for(i = 1; i < 15; i++)
        {
            fread(&jogadorTemp, sizeof(jogador), 1, scoreboard);
            if(i == cont)
            {
                fwrite(&jogador, sizeof(jogador), 1, scoreboardTemp);
            }
            fwrite(&jogadorTemp, sizeof(jogador), 1, scoreboardTemp);
        }
        rewind(scoreboard);
        rewind(scoreboardTemp);
        for(j = 1; j <= 15; j++)
        {
            fread(&jogadorTemp, sizeof(jogador), 1, scoreboardTemp);
            fwrite(&jogadorTemp, sizeof(jogador), 1, scoreboard);
        }
    }
    fclose(scoreboard);
    fclose(scoreboardTemp);
}*/
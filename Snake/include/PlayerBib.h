#ifndef PlayerBib
#define PlayerBib

typedef struct Jogador
{
	char nome[20];
	int pontos;
	int ratos;
	int vidas;
} Player;
void GetPlayerName(Player* AAA);
#endif
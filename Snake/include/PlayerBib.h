#ifndef PlayerBib
#define PlayerBib

typedef struct Jogador
{
	char nome[20];
	int pontos;
	int vidas;
} Player;
void GetPlayerName(Player* AAA);
void Save_Score (Player jogador);
void AddScore(Player *AAA);
#endif

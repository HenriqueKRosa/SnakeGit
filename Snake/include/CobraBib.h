#ifndef CobraBib
#define CobraBib

typedef struct str_Cobra
{
	int pos;
	//int hasFood;
	struct str_Cobra *next;
} Cobra;
void LeComando(char *comando);
int Movimentacao(Cobra *head, char *comando);
void DeletaCobra(Cobra *head);
void CriaNovaCobra(Cobra *head);
void IniciaCobra(Cobra *head);
#endif

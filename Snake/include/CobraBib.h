#ifndef CobraBib
#define CobraBib

typedef struct str_Cobra
{
	int pos;
	//int hasFood;
	struct str_Cobra *next;
} Cobra;
char LeComando();
int Movimentacao(Cobra *head);
void DeletaCobra(Cobra *head);
void CriaNovaCobra(Cobra *head);
void IniciaCobra(Cobra *head);
#endif

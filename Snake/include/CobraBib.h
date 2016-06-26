#ifndef CobraBib
#define CobraBib

typedef struct str_Cobra
{
	int pos;
	int hasFood;
	struct str_Cobra *next;
} Cobra;
/*typedef struct Rato
{
		struct Rato *next;
} Mouse;*/
char LeComando();
int Movimentacao(Cobra *head, char comando);
int RepeteComando(Cobra *head, char *initComando, char *lastcomand, Player AAA);
void DeletaCobra(Cobra *head);
void CriaNovaCobra(Cobra *head);
void AumentaCobra(Cobra *head);
int GetCobraSize(Cobra *head);
#endif

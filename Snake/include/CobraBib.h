#ifndef CobraBib
#define CobraBib


typedef struct str_Cobra
{
	int pos;
	struct str_Cobra *next;
} Cobra;
int GeraNumColunas();
void CarregaNivel();
int ImprimeMapa(Cobra *head, Cobra *condutor);
char LeComando();
int Maps(Cobra head);
int Movimentacao(Cobra head);
void Menu(Cobra head, Cobra condutor);
#endif

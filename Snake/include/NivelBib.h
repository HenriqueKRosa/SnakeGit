#ifndef NivelBib
#define NivelBib

void Print_Map(char Map_Name[20]);
void GetLinECol(int *linhas, FILE *mapaArqv);
int strcpy2(char *dest, int pos, char *src);
int makeMapa(FILE *mapaArqv, int linhas, char *nivel);
int CarregaNivel();
void ImprimeCabeca(char comando);
int ImprimeMapa(Cobra *head, char comando);
#endif

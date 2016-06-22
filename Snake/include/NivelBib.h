#ifndef NivelBib
#define NivelBib

void Print_Map(char Map_Name[20]);
void GetLinECol(int *linhas, FILE *mapaArqv);
void strcpy2(char *dest, int pos, char *src);
void makeMapa(FILE *mapaArqv, int linhas, char *nivel);
void CarregaNivel();
int ImprimeMapa(Cobra *head);
#endif

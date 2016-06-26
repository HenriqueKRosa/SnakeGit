#ifndef NivelBib
#define NivelBib

void Print_Map(char Map_Name[20]);
void GetLinECol(int *linhas, FILE *mapaArqv);
void strcpy2(char *dest, int pos, char *src, int *init);
void makeMapa(FILE *mapaArqv, int linhas, char *nivel, int *init);
int CarregaNivel();
void ImprimeCabeca(char comando);
int ImprimeMapa(Cobra *head, char comando);
void PosicoesLivres(Cobra* condutor, int* PosLivres, int* PosOcupadas, int NPosOcupadas);
int IsKPosDoArray(int k, int* ArrayDePosicoes, int TamanhoArray);
void CriaRato(Cobra *head);
#endif

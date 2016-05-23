#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "include/CobraBib.h"
#include <stdlib.h>

int maps(int pos[5]/*int map*/){
  int x = 0, i, k = 0, ch = 0, gg = 0;
  char maps[110];
  FILE *mapt;

  mapt = fopen("maps/test", "r");
  fread(maps, 1, 110, mapt);


  while(maps[x] != '\0')
  {
    for(i=0; i <= 9; i++)
    {
      for(k=0; k <= 4; k++)
      {
        if((x == pos[k]) && (maps[x] != '#'))
          {
          if (k == 0){
            printf("@");
            ch = 1;}
          else{
            printf("*");
            ch = 1;}
          }
	else if((x == pos[0]) && (maps[x] == '#'))
		gg = 1;
	if(k > 0)
	 if(pos[0] == pos[k])
		gg = 1;
      }

        if(!ch)
          printf("%c", maps[x]);
        x++;
        ch = 0;
        if(i == 9)
          printf("\n");
  }
}
	return gg;
}

int movimentacao(int pos[5])
{
    char comando;
    int GO = 0, i;
    scanf(" %c", &comando);

    comando = toupper(comando);
    switch (comando) {
      case 'W':
      pos[4] = 0;

      for(i = 4; i >= 0; i--)
      {
        if (i == 0)
          pos[i] = pos[i] - 10; //Número de colunas.
        else
          pos[i] = pos[i - 1];
      }
        break;
      case 'S':
      pos[4] = 0;

      for(i = 4; i >= 0; i--)
      {
        if (i == 0)
          pos[i] = pos[i] + 10; //Número de colunas.
        else
          pos[i] = pos[i - 1];
      }
        break;
      case 'A':
      pos[4] = 0;

      for(i = 4; i >= 0; i--)
      {
        if (i == 0)
          pos[i] = pos[i] - 1;
        else
          pos[i] = pos[i - 1];
      }
        break;
      case 'D':
      pos[4] = 0;

      for(i = 4; i >= 0; i--)
      {
        if (i == 0)
          pos[i] = pos[i] + 1;
        else
          pos[i] = pos[i - 1];
      }
        break;
      case 'Q':
	GO = 1;
	break;
    }
    return GO;
}

void menu(int pos[5])
{
 int gg = 0, GO = 0;
 
 do
 {
	 gg = movimentacao(pos);
	 system("clear");
	 GO = maps(pos);
 }while((!gg) && (!GO));
}

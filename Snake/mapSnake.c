#include <stdio.h>
#include <string.h>

void maps(int pos[5]){
  char map1[] = "###########        ##        ##        ##        ##        ##        ##        ##        ##        ###########";
  int x = 0, i, k = 0, ch = 0;

  while(map1[x] != '\0')
  {
    for(i=0; i <= 9; i++)
    {

    for(k=0; k <= 4; k++)
    {
      if(x == pos[k])
      {
      if (k == 0){
        printf("@");
        ch = 1;}
      else{
        printf("*");
        ch = 1;}
      }
    }

    if(!ch)
      printf("%c", map1[x]);
    x++;
    ch = 0;
    if(i == 9)
      printf("\n");
    }
  }
}

int main() {
  int x, y, pos[5], i =0;

  for(i=0; i <= 4; i++)
  {
  scanf("%d %d", &x, &y);
  pos[i] = y * 10 + x;
  }
  maps(pos);
  return 0;
}

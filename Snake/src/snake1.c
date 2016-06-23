#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "../include/CobraBib.h"
#include "../include/NivelBib.h"
#include "../include/PlayerBib.h"
#include "../include/MenuBib.h"
int nivelId = 0;
char nivel[500];
int colunas;

int main()
{
		int op;
			
		Inicio:
		Print_Title();
		op = Menu();
		
		switch(op)
		{
				case 1:
					system("cls");
					Jogo();
					puts("Press any key to return to main menu.");
					getch();
					goto Inicio;
					break;
				case 2:
					Stage_selection();
					break;
				case 3:
					puts("Nao implementado ainda!");
					getch();
					goto Inicio;
					break;
				case 4:
					return 0;
		}
		
		getch();
		return 0;
}
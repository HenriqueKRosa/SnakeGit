#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "../include/PlayerBib.h"
#include "../include/CobraBib.h"
#include "../include/NivelBib.h"
#include "../include/MenuBib.h"
int nivelId = 1;
char nivel[500];
int colunas = 0;

int main() //Jogo temporário
{
		int op, op1, win;
			
		Inicio:
		Print_Title();
		op = Menu();
		
		Opcao:
		switch(op)
		{
				case 1:
					system("cls");
					win = Jogo();
					if(win == 1)
					{
						nivelId++;
						goto Opcao;
					}
					puts("Press any key to return to main menu.");
					getch();
					goto Inicio;
					break;
				case 2:
					op1 = Stage_selection();
					switch(op1)
					{
						case 0:
							nivelId = 0;
							op = 1;
							goto Opcao;
							break;
						case 1:
							nivelId = 1;
							op = 1;
							goto Opcao;
							break;
						case 2:
							nivelId = 2;
							op = 1;
							goto Opcao;
							break;
						case 3:
							goto Inicio;
							break;
					}
					break;
				case 3:
					puts("Nao implementado ainda!");
					getch();
					goto Inicio;
					break;
				case 4:
					return 0;
		}
}
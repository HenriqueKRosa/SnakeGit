#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "include/CobraBib.h"
#include "include/MenuBib.h"
#include <stdlib.h>

void Print_Title(){
    printf("############################################################\n");
    printf("#                                                          #\n");
    printf("#   /----   |\\       |         /\\         |   /  |-------  #\n");
    printf("#  /        | \\      |        /  \\        |  /   |         #\n");
    printf("#  |        |  \\     |       /    \\       | /    |         # \n");
    printf("#  \\----    |   \\    |      /      \\      |/     |         #\n");
    printf("#        \\  |    \\   |     /--------\\     |\\     |-------  #\n");
    printf("#         | |     \\  |    /          \\    | \\    |         #\n");
    printf("#  \\     /  |      \\ |   /            \\   |  \\   |         #\n");
    printf("#   ----/   |       \\|  /              \\  |   \\  |-------  #\n");
    printf("#                                                          #\n");
    printf("############################################################\n\n");
}
void Create_Menu_Option(char Option_Text[20], int Menu_Number, int* Option_Number){

    int i;

    for(i=0;i<4;i++)
    {
            switch(i)
            {
                case 0: printf(" ");
                        break;
                case 1: printf(" ");
                        break;
                case 2: if(*Option_Number == Menu_Number)
                        {
                            printf(">");
                        }
                            else
                            {
                                printf(" ");
                            }
                        break;

                case 3: puts(Option_Text);
                        break;
            }
    }
}

int Menu() {

    int Option_Number;
    char Users_Input;

    Option_Number = 1;

    do
    {
        system("clear");
        Print_Title();
        Create_Menu_Option("Iniciar jogo\n", 1, &Option_Number);
        Create_Menu_Option("Scoreboard\n", 2, &Option_Number);
        Create_Menu_Option("Sair\n", 3, &Option_Number);
        scanf("%c", &Users_Input);
        if(Users_Input == 'w' && Option_Number > 1)
        {
            Option_Number--;
        }
        if(Users_Input == 's' && Option_Number < 3)
        {
            Option_Number++;
        }
    }
    while(Users_Input != 13);

return Option_Number;
}

void Jogo(Cobra *head)
{
	int isGameOver = 0, quit = 0;
	
	CarregaNivel();

	do
	{
		isGameOver = Movimentacao(head);
		system("clear");
		quit = ImprimeMapa(head);
	}while((isGameOver != 1) && (quit == 1));
}


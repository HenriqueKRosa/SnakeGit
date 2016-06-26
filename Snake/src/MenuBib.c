#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../include/PlayerBib.h"
#include "../include/CobraBib.h"
#include "../include/NivelBib.h"
#include "../include/MenuBib.h"
#include <conio.h>
#include <stdlib.h>
extern int nivelId;
extern int colunas;
extern char nivel[500];

void Print_Title(){
    printf("############################################################\n");
    printf("#                                                 _______  #\n");
    printf("#   /----   |\\       |         /\\         |   /  |         #\n");
    printf("#  /        | \\      |        /  \\        |  /   |         #\n");
    printf("#  |        |  \\     |       /    \\       | /    |         # \n");
    printf("#  \\----    |   \\    |      /      \\      |/     |         #\n");
    printf("#        \\  |    \\   |     /--------\\     |\\     |======   #\n");
    printf("#         | |     \\  |    /          \\    | \\    |         #\n");
    printf("#  \\     /  |      \\ |   /            \\   |  \\   |         #\n");
    printf("#   ----/   |       \\|  /              \\  |   \\  |_______  #\n");
    printf("#                                                          #\n");
    printf("############################################################\n\n");
}

void Create_Menu_Option(char Option_Text[20], int Menu_Number, int* Option_Number) //Cria botão no menu.
{
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

int Menu() //Função que cuida dos botões do menu e retorna a opção escolhida
{
    int Option_Number;
    char Users_Input;

    Option_Number = 1;

    do
    {
        system("cls");
        Print_Title();
        Create_Menu_Option("Iniciar jogo\n", 1, &Option_Number);
		Create_Menu_Option("Selecione o nivel\n", 2, &Option_Number);
        Create_Menu_Option("Scoreboard\n", 3, &Option_Number);
        Create_Menu_Option("Sair\n", 4, &Option_Number);
        Users_Input = getch();
        if(Users_Input == 'w' && Option_Number > 1)
        {
            Option_Number--;
        }
        if(Users_Input == 's' && Option_Number < 4)
        {
            Option_Number++;
        }
    }
    while(Users_Input != 13);

return Option_Number;
}

int Jogo() //Função que cria a "sessão de jogo" e une as outras funções para fazer o jogo funcionar.
{
	int /*isGameOver = 0,*/ quit = 0, init, win = 0, tam, ratos, vidas = 2;
	char comando = 'D', lastcomand = 'D';
	Cobra *head, *cobra1, *cobra2;
	Player AAA;
	
	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));
	cobra2 = malloc(sizeof(Cobra));
	
	init = CarregaNivel();
	
	head->pos = init;
	head->hasFood = 0;
	head->next = cobra1;
	cobra1->pos = 0;
	cobra1->hasFood = 0;
	cobra1->next = cobra2;
	cobra2->pos = 0;
	cobra2->hasFood = 0;
	cobra2->next = NULL;

	AAA.pontos = 15;
	
	GUI(AAA, vidas, ratos);
	ImprimeMapa(head, comando);
	nivel[init] = ' ';
	do
	{
		quit = RepeteComando(head, &comando, &lastcomand, AAA);
		if(quit == 2)
			win = 1;
	}while((quit == 0) && (win != 1));

	memset(nivel, 0, sizeof(nivel));
	puts("Game over");
	GetPlayerName(&AAA);
	return win;
}

void GUI(Player AAA, int vidas, int ratos) //Exibe na tela in-game com os dados do jogador.
{
	printf("Nivel: %d Ratos: %d/15 Vidas: %d\n", nivelId, AAA.pontos, ratos, vidas);
}

void WSControl(int Min_Option_Num, int Max_Option_Num, char* Users_Input, int* Stage_Number)
{
    *Users_Input = getch();
    if(*Users_Input == 'w' && *Stage_Number > Min_Option_Num)
        *Stage_Number = *Stage_Number - 1;
    if(*Users_Input == 's' && *Stage_Number < Max_Option_Num)
        *Stage_Number = *Stage_Number + 1;
}

int Stage_selection() //Retorna o número do nivel a ser carregado.
{
    int Stage_Number = 0;
    char Users_Input;

	do
	{
		system("cls");
		printf("\n\n");
		Create_Menu_Option("Nivel teste\n", 0, &Stage_Number);
		Create_Menu_Option("Nivel 1\n", 1, &Stage_Number);
		Create_Menu_Option("Nivel 2\n", 2, &Stage_Number);
		Create_Menu_Option("Menu principal\n", 3, &Stage_Number);
		printf("\n");
		switch(Stage_Number)
		{
			case 0: Print_Map("test.txt"); break;
			case 1: Print_Map("1.txt"); break;
			case 2: Print_Map("2.txt"); break;
		}
		WSControl(0, 3, &Users_Input, &Stage_Number);
	}while(Users_Input != 13);

	return Stage_Number;
}

void Show_Scoreboard ()
{
    char User_Input;
    Imprime_Jogadores();
    printf("\n  >Voltar\n");
    while(User_Input != 13)
    {
        User_Input = getch();
    }
}

void Imprime_Jogadores()
{
    FILE* jogadores;
    Player jogador;
    int i;
    jogadores = fopen("highscores/scoreboard.bin", "rb");
    for(i=1;i<=15;i++)
    {
        printf(" %d. ", i);
        fread(&jogador, sizeof(jogador), 1, jogadores);
        printf("%s\n", jogador.nome);
    }
}
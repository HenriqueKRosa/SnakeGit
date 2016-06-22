#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print_Map(char Map_Name[20])
{
    FILE *Map_File;
    char ch;
    char Map_Adress[25] = "maps/";
    strcat(Map_Adress, Map_Name);
    Map_File = fopen(Map_Adress, "r");
    while ( (ch = fgetc(Map_File) ) != EOF) {
		printf("%c",ch);
	}
	fclose(Map_File);
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
void WSControl(int Min_Option_Num, int Max_Option_Num, char* Users_Input, int* Stage_Number)
{
    *Users_Input = getch();
    if(*Users_Input == 'w' && *Stage_Number > Min_Option_Num)
        *Stage_Number = *Stage_Number - 1;
    if(*Users_Input == 's' && *Stage_Number < Max_Option_Num)
        *Stage_Number = *Stage_Number + 1;
}
int main ()
{
    int Stage_Number = 1;
    char Users_Input;

do
{
    system("cls");
    printf("\n\n");
    Create_Menu_Option("Nivel 1\n", 1, &Stage_Number);
    Create_Menu_Option("Nivel teste\n", 2, &Stage_Number);
    Create_Menu_Option("Menu principal\n", 3, &Stage_Number);
    printf("\n");
    switch(Stage_Number)
    {
        case 1: Print_Map("1.txt"); break;
        case 2: Print_Map("test.txt"); break;
    }
    WSControl(1, 3, &Users_Input, &Stage_Number);
}while(Users_Input != 13);
    return 0;
}

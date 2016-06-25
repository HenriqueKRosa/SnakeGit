#ifndef MenuBib
#define MenuBib

void Print_Title();
void Create_Menu_Option(char Option_Text[20], int Menu_Number, int* Option_Number);
int Menu();
int Jogo();
void GUI(Player AAA, int ratos, int vidas);
void GetPlayerName(Player* AAA);
void Imprime_Jogadores();
void Show_Scoreboard();
int Stage_selection();
void WSControl(int Min_Option_Num, int Max_Option_Num, char* Users_Input, int* Stage_Number);
#endif
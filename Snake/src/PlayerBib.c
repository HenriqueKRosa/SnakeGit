#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../include/PlayerBib.h"
#include "../include/CobraBib.h"
#include "../include/MenuBib.h"
#include "../include/NivelBib.h"
#include <stdlib.h>

void GetPlayerName(Player* AAA)
{
	char nomeTemp[20];
	
	puts("Enter a Player name: (Less than 20 characters long.)");
	do{
		gets(nomeTemp);
		if(strlen(nomeTemp) > 20)
			puts("Name too long! Try again.");
	}while(strlen(nomeTemp) > 20);
	strcpy(AAA->nome, nomeTemp);
}
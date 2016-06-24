#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "../include/CobraBib.h"
#include "../include/NivelBib.h"
#include "../include/PlayerBib.h"
#include "../include/MenuBib.h"
#include <stdlib.h>
extern char nivel[500];
extern int nivelId;
extern int colunas;

void LeComando(char *comando)
{
	*comando = getch();
	*comando = toupper(*comando);
}

int Movimentacao(Cobra *head, char *comando)
{
	int quit = 0;

	LeComando(comando);
	switch (*comando) {
		case 'W':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos - colunas;
			break;
		case 'S':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos + colunas;
			break;
		case 'A':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos - 1;
			break;
		case 'D':
			DeletaCobra(head);
			CriaNovaCobra(head);
			head->pos = head->pos + 1;
			break;
		case '+':
			AumentaCobra(head);
			break;
		case '-':
			DeletaCobra(head);
			break;
		case 'Q':
			quit = 1;
			break;
		case 'M':
			quit = 2;
			break;
	}
	return quit;
}

void CriaNovaCobra(Cobra *head)
{
	Cobra *nova;

	nova = malloc(sizeof(Cobra));
	nova->pos = head->pos;
	nova->next = head->next;
	head->next = nova;
}

void AumentaCobra(Cobra *head)
{
	Cobra *nova;
	
	nova = malloc(sizeof(Cobra));
	nova->pos = 0;
	nova->next = head->next;
	head->next = nova;
}

void DeletaCobra(Cobra *head)
{
	Cobra *tmp;

	tmp = head;

	while(tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
	
}
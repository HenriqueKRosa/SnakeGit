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

char LeComando()
{
	char comando;

	comando = getch();
	comando = toupper(comando);

	return comando;
}

int Movimentacao(Cobra *head)
{
	int quit = 0;

	switch (LeComando()) {
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
			CriaNovaCobra(head);
			break;
		case '-':
			DeletaCobra(head);
			break;
		case 'Q':
			quit = 1;
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

void IniciaCobra(Cobra *head)
{
	Cobra *cobra1, *cobra2, *cobra3;

	head = malloc(sizeof(Cobra));
	cobra1 = malloc(sizeof(Cobra));
	cobra2 = malloc(sizeof(Cobra));
	cobra3 = malloc(sizeof(Cobra));

	head->pos = 55;
	head->next = cobra1;
	cobra1->pos = 0;
	cobra1->next = cobra2;
	cobra2->pos = 0;
	cobra2->next = cobra3;
	cobra3->pos = 0;
	cobra3->next = NULL;
}
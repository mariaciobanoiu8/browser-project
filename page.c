/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "struct.h"
// Functie pentru accesarea paginii u id-ul specificat in tabul curent
void page(browser *tabs, Page *v, int n, int id, FILE *output)
{
	int i;
	// Cautam pagina, iar daca o gasim iesim din bucla
	for (i = 0; i < n; i++)
		if (v[i].id == id)
			break;
	// Daca nu gasim pagina, afisam mesajul de eroare
	if (i == n)
	{
		fprintf(output, "403 Forbidden\n");
		return;
	}
	// Initializarea unui pointer cu adresa nodului de dupa santinela
	list *copy = tabs->list->sentinel->next;
	// Cautarea tabului curent in lista de taburi
	while (copy->info != tabs->current)
		copy = copy->next;
	// Salvarea paginii curente a tabului curent
	Page *old = copy->info->currentPage;
	// Schimbarea paginii curente a tabului cu pagina cu id-ul specificat
	copy->info->currentPage = &v[i];
	// Alocarea memoriei pentru un nou nod de tip stiva
	stack *new = (stack *)malloc(sizeof(stack));
	// Verificam daca alocarea memoriei a esuat
	if (new == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		return;
	}
	// Initializarea noului nod al stivei cu pagina veche
	new->info = old;
	new->next = NULL;
	// Adaugam nodul in stiva Backward
	// Daca stiva e goala setam nodul ca primul
	if (copy->info->backwardStack == NULL)
		copy->info->backwardStack = new;
	// Altfel adaugam nodul in varful stivei
	else
	{
		new->next = copy->info->backwardStack;
		copy->info->backwardStack = new;
	}
	// Resetarea stivei Forward
	copy->info->forwardStack = NULL;
	// Modificam tabul curent
	tabs->current = copy->info;
}
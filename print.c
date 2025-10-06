/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
/*Functie pentru afisarea id-urilor taburilor deschise
si descrierea paginii curente a tabului curent*/
void print(browser tabs, FILE *output)
{
	// Initializarea unui pointer cu urmatorul nod de dupa santinela
	list *copy = tabs.list->sentinel->next;
	// Cautarea tabului curent in lista de taburi
	while (tabs.current != copy->info)
		copy = copy->next;
	// Memorarea pozitiei de start
	list *start = copy;
	// Afisarea id-urilor taburilor incepand cu tabul curent, in ordine circulara
	do
	{
		// Daca nodul curent nu e nodul santinela afisam id-ul
		if (copy->info != NULL)
			fprintf(output, "%d ", copy->info->id);
		copy = copy->next;
	} while (copy->info != start->info);
	// Afisarea descrierii paginii curente din tabul curent
	fprintf(output, "\n%s\n", tabs.current->currentPage->description);
}
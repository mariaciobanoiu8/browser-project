/*CIOBANOIU Maria - 314CC*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"
#include "print_reversed.h"
/*Functie pentru afisarea URL-urilor
paginilor accesate in tabul cu ID-ul specificat*/
void print_history(browser *tabs, int id, FILE *output)
{
	// Initializarea unei variabile cu 0 pentru a verifica daca exista pagini
	int ok = 0;
	// Initializarea unui pointer cu urmatorul nod de dupa santinela
	list *copy_list = tabs->list->sentinel->next;
	// Cautarea tabului cu ID-ul specificat
	while (copy_list != tabs->list->sentinel && copy_list->info->id != id)
		copy_list = copy_list->next;
	// Verificarea gasirii tabului
	if (copy_list != tabs->list->sentinel)
	{
		// Afisarea stivei Forward in ordine inversa
		if (copy_list->info->forwardStack != NULL)
			print_reversed(copy_list->info->forwardStack, output);
		// Afisarea paginii curente, daca exista
		if (copy_list->info->currentPage)
		{
			fprintf(output, "%s\n", copy_list->info->currentPage->url);
			ok = 1;
		}
		// Afisarea stivei Backward
		if (copy_list->info->backwardStack != NULL)
		{
			stack *copy_stack = copy_list->info->backwardStack;
			while (copy_stack != NULL)
			{
				fprintf(output, "%s\n", copy_stack->info->url);
				copy_stack = copy_stack->next;
			}
		}
	}
	// Daca nu exista pagina curenta se afiseaza mesajul de eroare
	if (ok == 0)
		fprintf(output, "403 Forbidden\n");
}
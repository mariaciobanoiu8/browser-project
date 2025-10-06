/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "init_page.h"
#include "init_tab.h"
// Functie pentru initializarea unui browser
void init_browser(browser *tabs, FILE *output)
{
	// Alocam memorie tabului curent
	tabs->current = (tab *)malloc(sizeof(tab));
	// Verificam daca alocarea memoriei a esuat
	if (tabs->current == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		return;
	}
	// Initializarea tabului curent cu tabul implicit
	init_tab(tabs->current, output);
	// Alocam memorie listei de taburi
	tabs->list = (tablist *)malloc(sizeof(tablist));
	// Verificam daca alocarea memoriei a esuat
	if (tabs->list == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		free(tabs->current);
		return;
	}
	// Alocam memorie santinelei
	tabs->list->sentinel = (list *)malloc(sizeof(list));
	// Verificam daca alocarea memoriei a esuat
	if (tabs->list->sentinel == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		free(tabs->current);
		free(tabs->list);
		return;
	}
	// Initializam santinela
	tabs->list->sentinel->info = NULL;
	// Alocam memorie unui nou nod in lista de taburi care contine tabul curent
	list *new = (list *)malloc(sizeof(list));
	// Verificam daca alocarea memoriei a avut succes
	if (new == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		free(tabs->current);
		free(tabs->list->sentinel);
		free(tabs->list);
		return;
	}
	// Initializam noul nod cu tabul curent
	new->info = tabs->current;
	// Legam noul nod in lista circulara dublu inlantuita de taburi
	tabs->list->sentinel->next = new;
	tabs->list->sentinel->prev = new;
	new->next = tabs->list->sentinel;
	new->prev = tabs->list->sentinel;
}
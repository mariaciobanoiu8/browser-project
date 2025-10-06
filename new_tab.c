/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "init_browser.h"
#include "init_page.h"
// Functie pentru crearea unui nou tab
void new_tab(browser *tabs, int k, FILE *output)
{
	// Alocam memorie pentru un nou nod de tip lista
	list *new = (list *)malloc(sizeof(list));
	// Verificam daca alocarea memoriei a esuat
	if (new == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		return;
	}
	// Alocam memorie pentru un nou tab
	new->info = (tab *)malloc(sizeof(tab));
	// verificam daca alocarea memoriei a esuat
	if (new->info == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		return;
	}
	// Initializam stivele Backward si Forward pentru noul tab
	new->info->backwardStack = NULL;
	new->info->forwardStack = NULL;
	// Alocam memoriei pentru o noua pagina
	new->info->currentPage = (Page *)malloc(sizeof(Page));
	// Verificam daca alocarea memoriei a esuat
	if (new->info->currentPage == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		return;
	}
	// Initializam pagina cu pagina implicita
	init_page(new->info->currentPage, output);
	// Setam id-ul noului tab
	new->info->id = k;
	// Adaugam noul tab la finalul listei, inaintea santinelei
	new->next = tabs->list->sentinel;
	new->prev = tabs->list->sentinel->prev;
	tabs->list->sentinel->prev->next = new;
	tabs->list->sentinel->prev = new;
	// Setam noul tab ca tab curent
	tabs->current = new->info;
}
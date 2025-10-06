/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "init_page.h"
// Functie pentru initializarea tabului implicit
void init_tab(tab *tab, FILE *output)
{
	// Initializam id-ul tabului cu 0
	tab->id = 0;
	// Alocam memorie paginii curente
	tab->currentPage = (Page *)malloc(sizeof(Page));
	// Verificam daca alocarea memoriei a esuat
	if (tab->currentPage == NULL)
	{
		fprintf(output, "Alocarea dinamica a esuat!\n");
		return;
	}
	// Initializam pagina curenta cu pagina implicita
	init_page(tab->currentPage, output);
	// Initializam stivele Backward si Forward
	tab->backwardStack = NULL;
	tab->forwardStack = NULL;
}
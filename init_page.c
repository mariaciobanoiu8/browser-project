/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
// Functie pentru initializarea paginii implicite
void init_page(Page *page, FILE *output)
{
	// Initializam id-ul cu 0;
	page->id = 0;
	// Initializam url-ul
	strcpy(page->url, "https://acs.pub.ro/");
	int n = strlen("Computer Science") + 1;
	// Alocam memorie descrierii
	page->description = (char *)malloc(n * sizeof(char));
	// Verificam daca alocarea memoriei a esuat
	if (page->description == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		return;
	}
	// Initializam descrierea
	strcpy(page->description, "Computer Science");
}
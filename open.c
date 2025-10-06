/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
// Functie pentru accesarea tabului cu id-ul specificat
void open(browser *tabs, int id, FILE *output)
{
	// Initializarea unui pointer cu adresa nodului de dupa nodul santinela
	list *copy = tabs->list->sentinel->next;
	// Parcurgerea listei
	while (copy != tabs->list->sentinel)
	{
		// Cautarea tabului cu id-ul specificat
		if (copy->info->id == id)
			// Daca este gasit tabul curent devine tabul cu id-ul specificat
			tabs->current = copy->info;
		copy = copy->next;
	}
	// Daca nu exista un tab cu id-ul specificat este afisat mesajul de eroare
	if (tabs->current->id != id)
		fprintf(output, "403 Forbidden\n");
}
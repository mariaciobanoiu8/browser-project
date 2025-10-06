/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
// Functie pentru accesarea tabului care se afla dupa tabul curent in lista
void next(browser *tabs)
{
	// Inițializarea unui pointer cu adresa urmatorului nod după santinela
	list *copy = tabs->list->sentinel->next;
	// Cautarea nodului curent in lista de taburi
	while (copy->info != tabs->current)
		copy = copy->next;
	// Daca in lista, nodul urmator e santinela, accesam nodul de dupa
	if (copy->next == tabs->list->sentinel)
		copy = copy->next;
	// Modificam tabul curent in tabul urmator acestuia
	tabs->current = copy->next->info;
}
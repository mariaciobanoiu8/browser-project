/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
// Functie pentru accesarea tabului care se afla in lista inaintea tabului curent
void prev(browser *tabs)
{
	// Initializarea unui pointer cu adresa urmatorului nod dupa santinela
	list *copy = tabs->list->sentinel->next;
	// Cautarea nodului curent in lista de taburi
	while (copy->info != tabs->current)
		copy = copy->next;
	// Daca in lista, nodul anterior e santinela, accesam nodul dinaintea ei
	if (copy->prev == tabs->list->sentinel)
		copy = copy->prev;
	// Modificam tabul curent in tabul dinaintea acestuia
	tabs->current = copy->prev->info;
}
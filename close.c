/*CIOBANOIU Maria - 314CC*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"
#include "free_stack.h"
// Functie care sterge tabul curent
void close(browser *tabs, FILE *output)
{
	// Daca tabul curent este cel implicit afisam mesajul de eroare
	if (tabs->current->id == 0)
	{
		fprintf(output, "403 Forbidden\n");
		return;
	}
	// Initializarea unui pointer cu adresa nodului de dupa santinela
	list *copy = tabs->list->sentinel->next;
	// Parcurgem lista de taburi
	while (copy != tabs->list->sentinel)
	{
		// Daca gasim tabul curent ne oprim
		if (copy->info == tabs->current)
			break;
		copy = copy->next;
	}
	// Salvam adresa nodului care trebuie sters
	list *delete = copy;
	// Setam tabul de dinaintea celui inchis ca tab curent
	tabs->current = copy->prev->info;
	// Modificam legaturile din lista pentru a scoate nodul
	copy->prev->next = copy->next;
	copy->next->prev = copy->prev;
	// Eliberam memoria pentru nodul eliminat
	/*Daca pagina curenta a tabului este cea implicita eliberam memoria
	alocata, altfel va fi eliberata in main*/
	if (delete->info->currentPage->id == 0)
	{
		free(delete->info->currentPage->description);
		free(delete->info->currentPage);
	}
	// Eliberam memoria pentru stivele Backward si Forward
	free_stack(&(delete->info->backwardStack));
	free_stack(&(delete->info->forwardStack));
	// Eliberam memoria pentru tab
	free(delete->info);
	// Eliberam memoria nodului
	free(delete);
}
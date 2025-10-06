/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "free_stack.h"
// Functie pentru eliberarea memoriei alocate unei liste
void free_list(tablist **List)
{
	// Daca lista e goala iesim din functie
	if (*List == NULL)
		return;
	list *aux;
	// Incepem de la nodul de dupa santinela
	list *copy = (*List)->sentinel->next;
	// Parcurgem lista pana ajungem la nodul santinela
	while ((*List)->sentinel != copy)
	{
		// Retinem adresa nodului curent al stivei
		aux = copy;
		// Accesam nodul urmator al stivei
		copy = copy->next;
		/*Eliberam memoria paginii daca este pagina implicita,
		altfel va fi eliberata in main*/
		if (aux->info->currentPage->id == 0)
		{
			free(aux->info->currentPage->description);
			free(aux->info->currentPage);
		}
		// Eliberam memoria alocata stivelor Backward si Forward
		free_stack(&(aux->info->backwardStack));
		free_stack(&(aux->info->forwardStack));
		// Eliberam memoria alocata tabului
		free(aux->info);
		// Eliberam memoria alocata nodului
		free(aux);
	}
	// Eliberam memoria alocata santinelei
	free((*List)->sentinel);
	// Eliberam memoria alocata listei
	free(*List);
}
/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
// Functie care elibereaza memoria alocata unei stive
void free_stack(stack **Stack)
{
	// Daca stiva este goala iesim din functie
	if (*Stack == NULL)
		return;
	stack *aux;
	// Parcurgem si eliberam fiecare nod al stivei
	while (*Stack != NULL)
	{
		// Retinem adresa nodului curent al stivei
		aux = *Stack;
		// Accesam nodul urmator al stivei
		*Stack = (*Stack)->next;
		/*Eliberam memoria paginii daca este pagina implicita,
		altfel va fi eliberata in main*/
		if (aux->info->id == 0)
		{
			free(aux->info->description);
			free(aux->info);
		}
		// Eliberam memoria alocata nodului
		free(aux);
	}
}
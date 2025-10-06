/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
// Functie pentru afisarea in ordine inversa a stivei
void print_reversed(stack *stack, FILE *output)
{
	// Daca stiva e goala iese din functie
	if (stack == NULL)
		return;
	// Apel recursiv pentru urmatorul nod
	print_reversed(stack->next, output);
	// Afiseaza URL-ul nodului curent
	fprintf(output, "%s\n", stack->info->url);
}
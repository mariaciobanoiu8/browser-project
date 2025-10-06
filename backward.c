/*CIOBANOIU Maria - 314CC*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"
// Functie pentru accesarea ultimei pagini adaugata in stiva Backward
void backward(browser *tabs, FILE *output)
{
	// Initializarea unui pointer cu primul element de dupa santinela
	list *copy_list = tabs->list->sentinel->next;
	// Parcurgerea listei de taburi pana la gasirea tabului curent
	while (copy_list->info != tabs->current)
		copy_list = copy_list->next;
	// Afisarea mesajului de eroare in cazul in care stiva Backward este goala
	if (copy_list->info->backwardStack == NULL)
	{
		fprintf(output, "403 Forbidden\n");
		return;
	}
	// Alocarea memoriei pentru un nou nod in stiva
	stack *new = (stack *)malloc(sizeof(stack));
	// Verificam daca alocarea memoriei a reusit
	if (new == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		return;
	}
	// Salvarea paginii curente in noul nod
	new->info = copy_list->info->currentPage;
	new->next = NULL;
	// Daca stiva Forward este goala, adaugam direct nodul
	if (copy_list->info->forwardStack == NULL)
		copy_list->info->forwardStack = new;
	// Altfel adaugam nodul in varful stivei
	else
	{
		new->next = copy_list->info->forwardStack;
		copy_list->info->forwardStack = new;
	}
	// Initializarea unui nod auxiliar cu nodul ce urmeaza a fi scos din stiva
	stack *aux = copy_list->info->backwardStack;
	// Mutarea pointerului spre urmatorul nod
	copy_list->info->backwardStack = copy_list->info->backwardStack->next;
	// Pagina curenta devine prima pagina din stiva initiala Backward
	copy_list->info->currentPage = aux->info;
	// Eliberam memoria nodului scos din stiva
	free(aux);
	// Aducem modificarile tabului curent
	tabs->current = copy_list->info;
}

/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "free_list.h"
#include "free_stack.h"
// Functie pentru eliberarea memoriei alocata browserului
void free_browser(browser *tabs)
{
	// Daca browserul e gol iesim din functie
	if (tabs == NULL)
		return;
	// Eliberam lista de taburi care contine si tabul curent
	free_list(&(tabs->list));
}
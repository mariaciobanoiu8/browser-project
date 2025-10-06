/*CIOBANOIU Maria - 314CC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "init_browser.h"
#include "new_tab.h"
#include "print.h"
#include "close.h"
#include "next.h"
#include "prev.h"
#include "open.h"
#include "page.h"
#include "forward.h"
#include "backward.h"
#include "print_history.h"
#include "free_browser.h"
int main(void)
{
	// Deschidem fisierele de intrare si de iesire
	FILE *input = fopen("tema1.in", "r");
	FILE *output = fopen("tema1.out", "w");
	int n, N, k = 0, id;
	char buffer[51], *command;
	browser tabs;
	// Initializam browserul
	init_browser(&tabs, output);
	// Citim numarul de pagini
	fscanf(input, "%d", &n);
	// Alocam memorie pentru numarul de pagini
	Page *v = (Page *)malloc(n * sizeof(Page));
	// Verificam daca alocarea memoriei a esuat
	if (v == NULL)
	{
		fprintf(output, "Alocarea memoriei a esuat!\n");
		fclose(input);
		fclose(output);
		return 0;
	}
	// Citim informatiile fiecarei pagini
	for (int i = 0; i < n; i++)
	{
		fscanf(input, "%d", &v[i].id);
		fscanf(input, "%s", v[i].url);
		fgetc(input); // Consumam newline-ul ramas
		fgets(buffer, sizeof(buffer), input);
		// Eliminam '\n' de la final
		buffer[strcspn(buffer, "\n")] = '\0';
		// Alocam memorie pentru descriere
		v[i].description = (char *)malloc(strlen(buffer) + 1);
		// Verificam daca alocarea memoriei a reusit
		if (v[i].description == NULL)
		{
			fprintf(output, "Alocarea memoriei a esuat!\n");
			fclose(input);
			fclose(output);
			return 0;
		}
		// Copiem textul
		strcpy(v[i].description, buffer);
	}
	// Citim numarul de comenzi
	fscanf(input, "%d", &N);
	// Consumam newlinw-ul
	fgetc(input);
	// Citim si executam comenzile
	for (int i = 0; i < N; i++)
	{
		// Citim comanda
		fgets(buffer, sizeof(buffer), input);
		// Eliminam '\n'
		buffer[strcspn(buffer, "\n")] = '\0';
		// Alocam memorie comenzii
		command = (char *)malloc(strlen(buffer) + 1);
		// Verificam daca alocarea memoriei a reusit
		if (command == NULL)
		{
			fprintf(output, "Alocarea memoriei a esuat!\n");
			fclose(input);
			fclose(output);
			return 0;
		}
		// Copiem textul
		strcpy(command, buffer);
		// Verificam comanda si apelam functia corespunzatoare
		if (strcmp(command, "NEW_TAB") == 0)
		{
			k++; // Incrementam numarul de taburi
			new_tab(&tabs, k, output);
		}
		else if (strcmp(command, "PRINT") == 0)
			print(tabs, output);
		else if (strcmp(command, "CLOSE") == 0)
			close(&tabs, output);
		else if (strcmp(command, "NEXT") == 0)
			next(&tabs);
		else if (strstr(command, "OPEN"))
		{
			// Extragem ID-ul tabului din comanda
			char *p = strtok(command, " ");
			p = strtok(NULL, " ");
			// Transformam stringul in numar intreg
			id = atoi(p);
			open(&tabs, id, output);
		}
		else if (strstr(command, "PAGE"))
		{
			// Extragem numarul paginii din comanda
			char *p = strtok(command, " ");
			p = strtok(NULL, " ");
			// Transformam stringul in numar intreg
			id = atoi(p);
			page(&tabs, v, n, id, output);
		}
		else if (strcmp(command, "PREV") == 0)
			prev(&tabs);
		else if (strcmp(command, "FORWARD") == 0)
			forward(&tabs, output);
		else if (strcmp(command, "BACKWARD") == 0)
			backward(&tabs, output);
		else if (strstr(command, "PRINT_HISTORY"))
		{
			// Extragem id-ul tabului din comanda
			char *p = strtok(command, " ");
			p = strtok(NULL, " ");
			// Transformam stringul in numar intreg
			id = atoi(p);
			print_history(&tabs, id, output);
		}
		// Eliberam memoria alocata comenzii
		free(command);
	}
	// Eliberam memoria alocata browserului
	free_browser(&tabs);
	// Eliminam memoria alocata descrierilor paginilor
	for (int i = 0; i < n; i++)
		free(v[i].description);
	// Eliberam memoria alocata vectorului de pagini
	free(v);
	// Inchidem fisierele de intrare si iesire
	fclose(input);
	fclose(output);
}
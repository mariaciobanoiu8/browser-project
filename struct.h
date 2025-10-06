/*CIOBANOIU Maria - CC*/
// Structura unei pagini
typedef struct page
{
	int id;
	char url[50], *description;
} Page;
// Structura unei stive
typedef struct stack
{
	Page *info;
	struct stack *next;
} stack;
// Structura unui tab
typedef struct tab
{
	int id;
	struct page *currentPage;
	struct stack *backwardStack, *forwardStack;
} tab;
// Structura unui nod al listei
typedef struct list
{
	tab *info;
	struct list *next, *prev;
} list;
// Structura unei liste
typedef struct tablist
{
	struct list *sentinel;
} tablist;
// Structura unui browser
typedef struct browser
{
	struct tab *current;
	struct tablist *list;
} browser;

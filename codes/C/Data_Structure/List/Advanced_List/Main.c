#include <stdlib.h>
#include "List.h"



int main() {
	List* minhaLista = createList();
	insertHead(minhaLista, 1);
	printList(minhaLista);
	insertHead(minhaLista, 3);
	printList(minhaLista);
	int a, b, c;
	scanf ("%d", &a);
	scanf ("%d", &b);
	scanf ("%d", &c);
	printf ("%d %d %d", a, b, c);
}


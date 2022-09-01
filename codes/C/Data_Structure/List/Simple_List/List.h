#ifndef LIST_H
#define LIST_H

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100 

#define OK 1
#define STRUCTURE_NOT_INITIALIZED -1
#define FULL_STRUCTURE-2
#define EMPTY_STRUCTURE -3
#define INVALID_INDEX -4
#define INVALID_PARAMETER -5

typedef struct {
	int items[MAX_SIZE];
	int last;
} List;

List* new_List();
int free_List(List* list);
int isEmpty_List(List* list);
int isFull_List(List* list);
int List_Push(List* list, int item, int pos);
int List_Pop(List* list, int* item, int pos);
int getElement_List(List* list, int* item, int pos);
int getSize_List(List* list, int* size);

#endif

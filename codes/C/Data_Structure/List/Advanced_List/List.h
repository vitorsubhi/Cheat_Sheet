#ifndef LISTA_ENC_H
#define LISTA_ENC_H

#define TRUE 1
#define FALSE 0

#define OK 1
#define NOT_INITIALIZED -1
#define EMPTY_STRUCTURE -2
#define INVALID_INDEX -3
#define INVALID_PARAMETER -4

typedef struct {
  int item;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
  int size;
} List;

List* createList();
int freeList(List* list);
int isEmpty(List* list);
int insertHead(List* list, int item);
int insertPos(List* list, int item, int pos);
int insertTail(List* list, int item);
int removeHead(List* list, int* item);
int removePos(List* list, int* item, int pos);
int removeTail(List* list, int* item);
int getItem(List* list, int* item, int pos);
int getSize(List* list, int* size);
void printList(List* list);

#endif

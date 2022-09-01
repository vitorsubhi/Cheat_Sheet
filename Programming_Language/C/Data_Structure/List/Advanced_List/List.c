#include <stdio.h>
#include <stdlib.h>
#include "List.h"

List* createList() {
    List* list = malloc(sizeof(*list));
    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

int freeList(List* list) {
    if (list == NULL)
        return NOT_INITIALIZED;

    // remove todos os elementos da list
    while(!isEmpty(list))
        removePos(list, NULL, 0);
    free(list);
    list = NULL;
    return OK;
}

int isEmpty(List* list) {
    if (list == NULL)
        return NOT_INITIALIZED;
    if (list->head == NULL)
        return TRUE;
    return FALSE;
}

Node* createNode(int item, Node* next) {
	Node *node = malloc(sizeof(*node));
	if (node == NULL)
        return NULL;
	node->item = item;
	node->next = next;
	return node;
}

int insertHead(List* list, int item) {
    if (list == NULL)
        return NOT_INITIALIZED;
    Node *newNode = createNode(item, list->head);
    if (newNode == NULL)
        return NOT_INITIALIZED;
    list->head = newNode;
    list->size++;
    return OK;
}

int insertPos(List* list, int item, int pos) {
    if (list == NULL)
        return NOT_INITIALIZED;
    if (pos < 0 || pos > list->size)
        return INVALID_INDEX;

    Node *newNode;
    if (pos == 0) {
        return insertHead(list, item);
    } else {
        // prepara para inserir
        Node *aux;
        aux = list->head;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }

        // adiciona o nó
        newNode = newNode = createNode(item, aux->next);
        if (newNode == NULL)
            return NOT_INITIALIZED;
        aux->next = newNode;
    }
    list->size++;
    return OK;
}

int insertTail(List* list, int item) {
    return insertPos(list, item, list->size);
}

int removeHead(List* list, int* item) {
    if (list == NULL)
        return NOT_INITIALIZED;
    if (isEmpty(list))
        return EMPTY_STRUCTURE;
    Node *aux = list->head;
    if (item != NULL)
        *item = aux->item;
    list->head = aux->next;
    free(aux);
    aux = NULL;
    list->size--;
    return OK;
}

int removePos(List* list, int* item, int pos) {
    if (list == NULL)
        return NOT_INITIALIZED;
    if (isEmpty(list))
        return EMPTY_STRUCTURE;
    if (pos < 0 || pos >= list->size)
        return INVALID_INDEX;

    Node *ant, *atual;
    if (pos == 0) {
        return removeHead(list, item);
    } else {
        // prepara para removePos
        ant = NULL;
        atual = list->head;
        for(int i = 0; i < pos; i++) {
            ant = atual;
            atual = atual->next;
        }

        // remove o nó atual
        ant->next = atual->next;
        if (item != NULL)
            *item = atual->item;
        free(atual);
        atual = NULL;
    }
    list->size--;
    return OK;
}

int removeTail(List* list, int* item) {
    return removePos(list, item, list->size - 1);
}

int getItem(List* list, int* item, int pos) {
    if (list == NULL)
        return NOT_INITIALIZED;
    if (isEmpty(list))
        return EMPTY_STRUCTURE;
    if (pos < 0 || pos >= list->size)
        return INVALID_INDEX;
    if (item == NULL)
        return INVALID_PARAMETER;
    Node *aux;
    aux = list->head;
    for(int i = 0; i < pos; i++) {
        aux = aux->next;
    }
    *item = aux->item;

    return OK;
}

int getSize(List* list, int* size) {
    if (list == NULL)
        return NOT_INITIALIZED;
    if (size == NULL)
        return INVALID_PARAMETER;
    *size = list->size;
    return OK;
}

void printList(List* list) {
    int qtdeElementos;
    getSize(list, &qtdeElementos);
    printf("[");
    for(int i = 0;i < qtdeElementos; i++) {
        int el;
        getItem(list, &el, i);
        printf(" %d ", el);
    }
    printf("]\n");
}

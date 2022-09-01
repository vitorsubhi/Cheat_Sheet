#include<stdio.h>
#include<stdlib.h>
#include "List.h"

List* new_List() {
    List* list = malloc(sizeof(*list));
    if (list == NULL)
        return NULL;
    list->last = 0;
    return list;
}

int free_List(List* list) {
    if (list == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    free(list);
    list = NULL;
    return OK;
}

int isFull_list(List* list) {
    if (list == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (list->last == MAX_SIZE)
        return TRUE;
    return FALSE;
}

int isEmpty_List(List* list) {
    if (list == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (list->last == 0)
        return TRUE;
    return FALSE;
}

int checkIndex(List* list, int pos, int include_last) {
    if (pos < 0)
        return FALSE;
    if ((include_last) && (pos > list->last))
        return FALSE;
    if ((!include_last) && (pos >= list->last))
        return FALSE;
    return TRUE;
}

int List_Push(List* list, int item, int pos) {
    if (list == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isFull_list(list))
        return ESTRUTURA_CHEIA;
    if (!checkIndex(list, pos, TRUE))
        return INVALID_INDEX;

    // Desloca elementos para a direita.
    for(int i = list->last; i > pos; i--)  {
        list->items[i] = list->items[i - 1];
    }
    list->items[pos] = item;
    list->last++;
    return OK;
}

int List_Pop(List* list, int* item, int pos) {
    if (list == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isEmpty_List(list))
        return EMPTY_STRUCTURE;
    if (!checkIndex(list, pos, FALSE))
        return INVALID_INDEX;

    if (item != NULL)
        *item = list->items[pos];

    // Desloca elementos para a esquerda.
    for(int i = pos; i < (list->last - 1); i++)  {
        list->items[i] = list->items[i + 1];
    }
    list->last--;
    return OK;
}

int getElement_List(List* list, int* item, int pos) {
    if (list == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isEmpty_List(list))
        return EMPTY_STRUCTURE;
    if (!checkIndex(list, pos, FALSE))
        return INVALID_INDEX;
    if (item == NULL)
        return INVALID_PARAMETER;
    *item = list->items[pos];
    return OK;
}

int getSize_List(List* list, int* size) {
    if (list == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (size == NULL)
        return INVALID_PARAMETER;
    *size = list->last;
    return OK;
}

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int incrementar(int i) {
  // ou (i + 1) % TAM_MAX
  if (i == MAX_SIZE - 1) return 0;
  else return i + 1;
}


Queue* new_Queue() {
    Queue* queue = malloc(sizeof(*queue));
    if (queue == NULL)
        return NULL;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

int free_Queue(Queue* queue) {
    if (queue == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    free(queue);
    queue = NULL;
    return OK;
}

int isFull_Queue(Queue* queue) {
    if (queue == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (incrementar(queue->tail) == queue->head)
        return TRUE;
    return FALSE;
}

int isEmpty_Queue(Queue* queue) {
    if (queue == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (queue->head == queue->tail)
        return TRUE;
    return FALSE;
}

int Queue_Push(Queue* queue, int item) {
    if (queue == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isFull_Queue(queue))
        return FULL_STRUCTURE;
    queue->items[queue->tail] = item;
    queue->tail = incrementar(queue->tail);
    return OK;
}

int Queue_Pop(Queue* queue, int* item) {
    if (queue == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isEmpty_Queue(queue))
        return EMPTY_STRUCTURE;
    if (item != NULL)
        *item = queue->items[queue->head];
    queue->head = incrementar(queue->head);
    return OK;
}

int getHead_Queue(Queue* queue, int* item) {
    if (queue == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isEmpty_Queue(queue))
        return EMPTY_STRUCTURE;
    if (item == NULL)
        return INVALID_PARAMETERS;
    *item = queue->items[queue->head];
    return OK;
}

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

#define OK 0
#define STRUCTURE_NOT_INITIALIZED -1
#define EMPTY_STRUCTURE -2
#define FULL_STRUCTURE -3
#define INVALID_PARAMETERS -4

// Declaração da estrutura de uma Fila.
typedef struct {
    int items[MAX_SIZE];
    int head;
    int tail;
} Queue;


Queue* new_Queue();
int isEmpty_Queue(Queue* queue);
int isFull_Queue(Queue* queue);
int Queue_Push(Queue* queue, int item);
int Queue_Pop(Queue* queue, int* item);
int Head_Queue(Queue* queue, int* item);
int free_Queue(Queue* queue);

#endif

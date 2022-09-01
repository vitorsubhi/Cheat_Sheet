#include <stdio.h>
#include "Queue.h"

void print_Queue(Queue* queue) {
    Queue* queue_aux = new_Queue();
    int item;
    while(!isEmpty_Queue(queue)) {
        Queue_Pop(queue, &item);
        printf("%d\n", item);
        Queue_Push(queue_aux, item);
    }
    while(!isEmpty_Queue(queue_aux)) {
        Queue_Pop(queue_aux, &item);
        Queue_Push(queue_aux, item);
    }
    free_Queue(queue_aux);
}


int main() {
    Queue* queue = new_Queue();

    Queue_Push(queue, 10);
    Queue_Push(queue, 20);
    Queue_Push(queue, 30);
    //imprimirFila(queue);

    //int i;
    //remover(queue, &i);
    //printf("Elemento removido: %d\n", i);

    //remover(queue, &i);
    //printf("Elemento removido: %d\n", i);

    //imprimirFila(queue);

    return 0;
}

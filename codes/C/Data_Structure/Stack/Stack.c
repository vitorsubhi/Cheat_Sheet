#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

Stack* new_Stack() {
    Stack* stack = malloc(sizeof(*stack));
    if (stack == NULL)
        return NULL;
    stack->top = 0;
    return stack;
}

int liberarPilha(Stack* stack) {
    if (stack == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    free(stack);
    stack = NULL;
    return OK;
}

int isFull_Stack(Stack* stack) {
    if (stack == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (stack->top == MAX_SIZE)
        return TRUE;
    return FALSE;
}

int isEmpty_Stack(Stack* stack) {
    if (stack == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (stack->top == 0)
        return TRUE;
    return FALSE;
}

int Stack_Push(Stack* stack, int item) {
    if (stack == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isFull_Stack(stack))
        return FULL_STRUCTURE;
    stack->items[stack->top] = item;
    stack->top++;
    return OK;
}

int Stack_Pop(Stack* stack, int* item) {
    if (stack == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isEmpty_Stack(stack))
        return EMPTY_STRUCTURE;
    if (item != NULL)
        *item = stack->items[stack->top - 1];
    stack->top--;
    return OK;
}

int getTop_Stack(Stack* stack, int* item) {
    if (stack == NULL)
        return STRUCTURE_NOT_INITIALIZED;
    if (isEmpty_Stack(stack))
        return EMPTY_STRUCTURE;
    if (item == NULL)
        return INVALID_PARAMETER;
    *item = stack->items[stack->top - 1];
    return OK;
}
